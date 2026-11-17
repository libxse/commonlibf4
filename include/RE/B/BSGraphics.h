#pragma once

#include "RE/B/BSCriticalSection.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTAtomicValue.h"
#include "RE/B/BSTHashMap.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiPoint4.h"
#include "RE/N/NiPointer.h"
#include "RE/N/NiRect.h"
#include "RE/N/NiTexture.h"

#include "REX/W32/D3D11.h"

namespace RE
{
	class BSD3DResourceCreator;
	class BSEventFlag;
	class NiCamera;
	class NiTransform;

	namespace BSGraphics
	{
		class AlphaTestZPrePassDrawData;
		class DynamicTriShape;
		class DynamicTriShapeDrawData;
		enum class Format;
		class Texture;
		class TriShape;

		enum class AlphaBlendAlphaToCoverage : std::int32_t
		{
			kDisabled,
			kEnabled
		};

		enum class AlphaBlendMode : std::int32_t
		{
			kDisabled,
			kAlpha,               // SRC_ALPHA, INV_SRC_ALPHA
			kAdditiveAlpha,       // SRC_ALPHA, ONE
			kMultiply,            // DEST_COLOR, ZERO; alpha ONE, ZERO
			kPremultipliedAlpha,  // ONE, INV_SRC_ALPHA
			kAdditive,            // ONE, ONE
			kMultiplyIndependent  // independent: RT0 kMultiply, RT1-7 kAlpha
		};

		enum class AlphaBlendWriteMode : std::int32_t
		{
			kNone,
			kRGB,
			kRGBA,
			kRG,
			kBA,
			kR,
			kG,
			kB,
			kA,
			kAlphaOnlyRT0,  // independent: RT0 A, RT1-3 RGB, RT4-7 none
			kAlphaOnlyRT1,
			kAlphaOnlyRT2,
			kAlphaOnlyRT3
		};

		enum class RasterStateCullMode : std::int32_t
		{
			kNone,
			kBack,
			kFront
		};

		enum class RasterStateDepthBiasMode : std::int32_t
		{
			kNone = 0,
			kShadowDepth = 8  // DepthBias 12, slope 6.0, clamp -100
		};

		enum class RasterStateFillMode : std::int32_t
		{
			kSolid,
			kWireframe
		};

		enum class RasterStateScissorMode : std::int32_t
		{
			kDisabled,
			kEnabled
		};

		enum class MultiSampleLevel : std::int32_t
		{
			kNone,
			kTwo,
			kFour,
			kEight
		};

		enum class SetRenderTargetMode : std::int32_t
		{
			kClear = 0x0,
			kClearDepth = 0x1,
			kClearStencil = 0x2,
			kNoClear = 0x3,
			kRestore = 0x3,
			kForceCopyRestore = 0x4,
			kInit = 0x5
		};

		// Logical IDs; pooled targets must be acquired before platform lookup.
		enum class RenderTargetID : std::int32_t
		{
			kNone = -1,
			kFrameBuffer = 0,
			kMain = 1,
			kMainCopy = 2,
			kSSRPrepass = 4,
			kSSR = 5,
			kSSRBlurred0 = 6,
			kSSRBlurred1 = 7,
			kSSRDepth = 8,
			kRefractionNormals = 14,
			kMenuBackground = 15,
			kGBufferAlbedoSpecular = 26,
			kGBufferNormal = 27,
			kGBufferEnvironment = 29,
			kGBufferAmbient = 30,
			kGBufferEmissive = 31,
			kGBufferMotionVectors = 32,
			kDiffuseLight = 33,
			kDiffuseSpecular = 34,
			kDiffuseLightTiled = 35,
			kDiffuseSpecularTiled = 36,
			kAmbientOcclusion = 37,
			kAmbientOcclusionHalf = 39,
			kSAOCameraZ = 40,
			kPauseFreezeFrame = 54,
			kPipboy = 60,
			kPipboySwap = 61,
			kScreenshot = 63,
			kRainOcclusion = 86,
			kCount = 100
		};

		enum class DepthStencilTargetID : std::int32_t
		{
			kUnbound = -1,
			kMain = 1,
			kCubemapReflections = 7,
			kRainOcclusion = 8,
			kCount = 12
		};

		enum class CubeMapRenderTargetID : std::int32_t
		{
			kNone = -1,
			kReflections = 0,
			kCount = 1
		};

		enum class RenderTargetCreationMode : std::uint8_t
		{
			kPooled = 0,
			kPersistent = 1,
			kOnDemand = 2
		};

		enum class ShaderFlags : std::uint32_t
		{
			DIRTY_RENDERTARGET = 0x1,
			DIRTY_VIEWPORT = 0x2,
			DIRTY_DEPTH_STENCIL_STATE = 0x4,
			DIRTY_RASTERIZER_STATE = 0x8,
			DIRTY_BLEND_STATE = 0x10,
			DIRTY_INPUT_LAYOUT = 0x20,
			DIRTY_PRIMITIVE_TOPOLOGY = 0x40
		};

		enum class TAA_STATE : std::int32_t
		{
			kDisabled,
			kEnabled
		};

		enum class TextureFileFormat : std::int32_t
		{
			kBMP = 0,
			kJPG = 1,
			kTGA = 2,
			kPNG = 3,
			kDDS = 4,
			kPPM = 5,
			kDIB = 6,
			kHDR = 7,
			kPFM = 8,
		};

		enum class TextureFilterMode : std::int32_t
		{
			kNearest = 0x0,
			kBilerp = 0x1,
			kTrilerp = 0x2,
			kAniso = 0x3,
			kCompBilerp = 0x4,
		};

		enum class TextureAddressMode : std::int32_t
		{
			kClamp_S_Clamp_T = 0x0,
			kClamp_S_Wrap_T = 0x1,
			kWrap_S_Clamp_T = 0x2,
			kWrap_S_Wrap_T = 0x3,
		};

		enum class Usage : std::int32_t
		{
			kDefault = 0x0,
			kImmutable = 0x1,
			kDynamic = 0x2,
			kStaging = 0x3
		};

		class Buffer
		{
		public:
			// members
			REX::W32::ID3D11Buffer*              buffer;              // 00
			void*                                data;                // 08
			Buffer*                              next;                // 10
			REX::W32::ID3D11ShaderResourceView*  shaderResource;      // 18
			REX::W32::ID3D11UnorderedAccessView* unorderedAccess;     // 20
			BSEventFlag*                         requestEventToWait;  // 28
			std::uint32_t                        maxDataSize;         // 30
			std::uint32_t                        dataSize;            // 34
			std::uint32_t                        refCount;            // 38
			BSTAtomicValue<std::uint32_t>        SRAcquire;           // 3C
			BSTAtomicValue<std::uint32_t>        UAVAcquire;          // 40
			BSTAtomicValue<std::uint32_t>        pendingRequests;     // 44
			std::uint32_t                        dataOffset;          // 48
			bool                                 invalidCpuData;      // 4C
			bool                                 heapAllocated;       // 4D
			volatile bool                        pendingCopy;         // 4E
		};
		static_assert(sizeof(Buffer) == 0x50);

		class VertexBuffer :
			public Buffer
		{
		public:
		};
		static_assert(sizeof(VertexBuffer) == 0x50);

		class IndexBuffer :
			public Buffer
		{
		public:
		};
		static_assert(sizeof(IndexBuffer) == 0x50);

		class ByteBuffer :
		    public Buffer
		{
		public:
		};
		static_assert(sizeof(ByteBuffer) == 0x50);

		class StructuredBuffer
		{
		public:
			// members
			REX::W32::ID3D11Buffer*       buffer;              // 00
			std::byte                     pad08[0x20];         // 08
			BSEventFlag*                  requestEventToWait;  // 28
			BSTAtomicValue<std::uint32_t> pendingRequests;     // 30
			std::byte                     pad34[0xC];          // 34
		};
		static_assert(sizeof(StructuredBuffer) == 0x40);

		class TextureHeader
		{
		public:
			// members
			std::uint16_t height = 0;    // 0
			std::uint16_t width = 0;     // 2
			std::uint8_t  mipCount = 0;  // 4
			std::uint8_t  format = 0;    // 5
			std::uint8_t  flags = 0;     // 6
			std::uint8_t  tilemode = 0;  // 7
		};
		static_assert(sizeof(TextureHeader) == 0x8);

		class Texture
		{
		public:
			// members
			REX::W32::ID3D11ShaderResourceView* srView;       // 00
			REX::W32::ID3D11Texture2D*          texture;      // 08
			std::byte                           pad10[0x18];  // 10
			TextureHeader                       header;       // 28
			std::byte                           pad30[0x10];  // 30
		};
		static_assert(sizeof(Texture) == 0x40);

		class ConstantGroup
		{
		public:
			// members
			REX::W32::ID3D11Buffer* buffer{ nullptr };             // 00
			float*                  data{ nullptr };               // 08
			bool                    dataIsCPUWorkBuffer{ false };  // 10
		};
		static_assert(sizeof(ConstantGroup) == 0x18);

		class ComputeShader
		{
		public:
			// members
			std::uint32_t                  id{ 0 };                 // 00
			REX::W32::ID3D11ComputeShader* shader{ nullptr };       // 08
			std::uint32_t                  byteCodeSize{ 0 };       // 10
			BSGraphics::ConstantGroup      constantBuffers[3];      // 18
			std::uint64_t                  shaderDesc{ 0 };         // 60
			std::int8_t                    constantTable[32]{ 0 };  // 68
		};
		static_assert(sizeof(ComputeShader) == 0x88);

		class DomainShader
		{
		public:
			// members
			std::uint32_t                 id{ 0 };                 // 00
			REX::W32::ID3D11DomainShader* shader{ nullptr };       // 08
			std::uint32_t                 byteCodeSize{ 0 };       // 10
			BSGraphics::ConstantGroup     constantBuffers[3]{};    // 18
			std::uint64_t                 shaderDesc{ 0 };         // 60
			std::int8_t                   constantTable[32]{ 0 };  // 68
		};
		static_assert(sizeof(DomainShader) == 0x88);

		class HullShader
		{
		public:
			// members
			std::uint32_t               id{ 0 };                 // 00
			REX::W32::ID3D11HullShader* shader{ nullptr };       // 08
			std::uint32_t               byteCodeSize{ 0 };       // 10
			BSGraphics::ConstantGroup   constantBuffers[3];      // 18
			std::uint64_t               shaderDesc{ 0 };         // 60
			std::int8_t                 constantTable[32]{ 0 };  // 68
		};
		static_assert(sizeof(HullShader) == 0x88);

		class PixelShader
		{
		public:
			// members
			std::uint32_t                id{ 0 };                 // 00
			REX::W32::ID3D11PixelShader* shader{ nullptr };       // 08
			BSGraphics::ConstantGroup    constantBuffers[3];      // 10
			std::int8_t                  constantTable[32]{ 0 };  // 58
		};
		static_assert(sizeof(PixelShader) == 0x78);

		class VertexShader
		{
		public:
			// members
			std::uint32_t                 id{ 0 };                 // 00
			REX::W32::ID3D11VertexShader* shader{ nullptr };       // 08
			std::uint32_t                 byteCodeSize{ 0 };       // 10
			BSGraphics::ConstantGroup     constantBuffers[3];      // 18
			std::uint64_t                 shaderDesc{ 0 };         // 60
			std::int8_t                   constantTable[32]{ 0 };  // 68
		};
		static_assert(sizeof(VertexShader) == 0x88);

		class CubeMapRenderTarget
		{
		public:
			// members
			REX::W32::ID3D11Texture2D*          texture;    // 00
			REX::W32::ID3D11RenderTargetView*   rtView[6];  // 08
			REX::W32::ID3D11ShaderResourceView* srView;     // 38
		};
		static_assert(sizeof(CubeMapRenderTarget) == 0x40);

		class DepthStencilTarget
		{
		public:
			// members
			REX::W32::ID3D11Texture2D*          texture;                        // 00
			REX::W32::ID3D11DepthStencilView*   dsView[4];                      // 08
			REX::W32::ID3D11DepthStencilView*   dsViewReadOnlyDepth[4];         // 28
			REX::W32::ID3D11DepthStencilView*   dsViewReadOnlyStencil[4];       // 48
			REX::W32::ID3D11DepthStencilView*   dsViewReadOnlyDepthStencil[4];  // 68
			REX::W32::ID3D11ShaderResourceView* srViewDepth;                    // 88
			REX::W32::ID3D11ShaderResourceView* srViewStencil;                  // 90
		};
		static_assert(sizeof(DepthStencilTarget) == 0x98);

		class RenderTarget
		{
		public:
			// members
			REX::W32::ID3D11Texture2D*           texture;      // 00
			REX::W32::ID3D11Texture2D*           copyTexture;  // 08
			REX::W32::ID3D11RenderTargetView*    rtView;       // 10
			REX::W32::ID3D11ShaderResourceView*  srView;       // 18
			REX::W32::ID3D11ShaderResourceView*  copySRView;   // 20
			REX::W32::ID3D11UnorderedAccessView* uaView;       // 28
		};
		static_assert(sizeof(RenderTarget) == 0x30);

		class RendererWindow
		{
		public:
			template <class T = std::int32_t>
			[[nodiscard]] NiRect<T> GetWindowRect() const
			{
				return {
					static_cast<T>(windowX),
					static_cast<T>(windowX + windowWidth),
					static_cast<T>(windowY),
					static_cast<T>(windowY + windowHeight)
				};
			}

			// members
			REX::W32::HWND            hwnd;                   // 00
			std::int32_t              windowX;                // 08
			std::int32_t              windowY;                // 0C
			std::int32_t              windowWidth;            // 10
			std::int32_t              windowHeight;           // 14
			REX::W32::IDXGISwapChain* swapChain;              // 18
			RenderTarget              swapChainRenderTarget;  // 20
		};
		static_assert(sizeof(RendererWindow) == 0x50);

		class ViewData
		{
		public:
			// members
			NiRect<float> viewPort;                       // 000
			NiPoint2      viewDepthRange;                 // 010
			__m128        viewUp;                         // 020
			__m128        viewRight;                      // 030
			__m128        viewDir;                        // 040
			__m128        viewMat[4];                     // 050
			__m128        projMat[4];                     // 090
			__m128        viewProjMat[4];                 // 0D0
			__m128        viewProjUnjittered[4];          // 110
			__m128        currentViewProjUnjittered[4];   // 150
			__m128        previousViewProjUnjittered[4];  // 190
			__m128        inv1stPersonProjMat[4];         // 1D0
		};
		static_assert(sizeof(ViewData) == 0x210);

		class alignas(0x10) RendererShadowState
		{
		public:
			// members
			std::uint32_t                                stateUpdateFlags;                 // 000
			std::uint32_t                                vsResourceModifiedBits;           // 004
			std::uint32_t                                vsSamplerModifiedBits;            // 008
			std::uint32_t                                dsResourceModifiedBits;           // 00C
			std::uint32_t                                dsSamplerModifiedBits;            // 010
			std::uint32_t                                psResourceModifiedBits;           // 014
			std::uint32_t                                psSamplerModifiedBits;            // 018
			std::uint32_t                                csResourceModifiedBits;           // 01C
			std::uint32_t                                csSamplerModifiedBits;            // 020
			std::uint32_t                                csUAVModifiedBits;                // 024
			bool                                         readOnlyDepth;                    // 028
			bool                                         readOnlyStencil;                  // 029
			std::byte                                    pad02A[0x2];                      // 02A
			std::int32_t                                 renderTargets[8];                 // 02C
			std::int32_t                                 depthStencil;                     // 04C
			std::int32_t                                 depthStencilSlice;                // 050
			std::int32_t                                 cubeMapRenderTarget;              // 054
			std::int32_t                                 cubeMapRenderTargetView;          // 058
			REX::TEnum<SetRenderTargetMode>              setRenderTargetMode[8];           // 05C
			REX::TEnum<SetRenderTargetMode>              setDepthStencilMode;              // 07C
			REX::TEnum<SetRenderTargetMode>              setCubeMapRenderTargetMode;       // 080
			std::int32_t                                 currentRenderTargetIndex;         // 084
			std::int32_t                                 currentDepthStencilTargetIndex;   // 088
			std::int32_t                                 currentCubeMapRenderTargetIndex;  // 08C
			REX::W32::D3D11_VIEWPORT                     viewPort;                         // 090
			std::int32_t                                 depthStencilDepthMode;            // 0A8
			std::int32_t                                 depthStencilStencilMode;          // 0AC
			std::int32_t                                 depthStencilExtraMode;            // 0B0
			std::uint32_t                                stencilRef;                       // 0B4
			REX::TEnum<RasterStateFillMode>              rasterStateFillMode;              // 0B8
			REX::TEnum<RasterStateCullMode>              rasterStateCullMode;              // 0BC
			REX::TEnum<RasterStateDepthBiasMode>         rasterStateDepthBiasMode;         // 0C0
			REX::TEnum<RasterStateScissorMode>           rasterStateScissorMode;           // 0C4
			REX::TEnum<AlphaBlendMode>                   alphaBlendMode;                   // 0C8
			REX::TEnum<AlphaBlendAlphaToCoverage>        alphaBlendAlphaToCoverage;        // 0CC
			REX::TEnum<AlphaBlendWriteMode>              alphaBlendWriteMode;              // 0D0
			std::byte                                    pad0D4[0x8];                      // 0D4
			REX::TEnum<TextureAddressMode>               vsTextureAddressMode[16];         // 0DC
			REX::TEnum<TextureFilterMode>                vsTextureFilterMode[16];          // 11C
			REX::W32::ID3D11ShaderResourceView*          vsTexture[16];                    // 160
			std::uint32_t                                vsTextureMinLODMode[16];          // 1E0
			REX::TEnum<TextureAddressMode>               dsTextureAddressMode[16];         // 220
			REX::TEnum<TextureFilterMode>                dsTextureFilterMode[16];          // 260
			REX::W32::ID3D11ShaderResourceView*          dsTexture[16];                    // 2A0
			std::uint32_t                                dsTextureMinLODMode[16];          // 320
			REX::TEnum<TextureAddressMode>               psTextureAddressMode[16];         // 360
			REX::TEnum<TextureFilterMode>                psTextureFilterMode[16];          // 3A0
			REX::W32::ID3D11ShaderResourceView*          psTexture[16];                    // 3E0
			std::uint32_t                                psTextureMinLODMode[16];          // 460
			REX::TEnum<TextureAddressMode>               csTextureAddressMode[16];         // 4A0
			REX::TEnum<TextureFilterMode>                csTextureFilterMode[16];          // 4E0
			REX::W32::ID3D11ShaderResourceView*          csTexture[16];                    // 520
			std::uint32_t                                csTextureMinLODMode[16];          // 5A0
			REX::W32::ID3D11UnorderedAccessView*         csUAV[8];                         // 5E0
			std::byte                                    pad620[0x60];                     // 620
			std::uint64_t                                vertexDesc;                       // 680
			VertexShader*                                currentVertexShader;              // 688
			DomainShader*                                currentDomainShader;              // 690
			HullShader*                                  currentHullShader;                // 698
			PixelShader*                                 currentPixelShader;               // 6A0
			REX::TEnum<REX::W32::D3D_PRIMITIVE_TOPOLOGY> primitiveTopology;                // 6A8
			std::byte                                    pad6AC[0x24];                     // 6AC
			ViewData                                     cameraData;                       // 6D0
			float                                        clearColor[4];                    // 8E0
			float                                        previousClearColor[4];            // 8F0
			std::byte                                    pad900[0x10];                     // 900
		};
		static_assert(sizeof(RendererShadowState) == 0x910);

		class RendererData
		{
		public:
			// members
			RendererShadowState*               shadowState;              // 0000
			BSD3DResourceCreator*              resourceCreator;          // 0008
			std::uint32_t                      adapter;                  // 0010
			REX::W32::DXGI_RATIONAL            desiredRefreshRate;       // 0014
			REX::W32::DXGI_RATIONAL            actualRefreshRate;        // 001C
			REX::W32::DXGI_MODE_SCALING        scaleMode;                // 0024
			REX::W32::DXGI_MODE_SCANLINE_ORDER scanlineMode;             // 0028
			std::int32_t                       fullScreen;               // 002C
			bool                               appFullScreen;            // 0030
			bool                               borderlessWindow;         // 0031
			bool                               vsync;                    // 0032
			bool                               initialized;              // 0033
			bool                               requestWindowSizeChange;  // 0034
			std::uint32_t                      newWidth;                 // 0038
			std::uint32_t                      newHeight;                // 003C
			std::uint32_t                      presentInterval;          // 0040
			REX::W32::ID3D11Device*            device;                   // 0048
			REX::W32::ID3D11DeviceContext*     context;                  // 0050
			RendererWindow                     renderWindow[32];         // 0058
			RenderTarget                       renderTargets[101];       // 0A58
			DepthStencilTarget                 depthStencilTargets[13];  // 1D48
			CubeMapRenderTarget                cubeMapRenderTargets[2];  // 2500
			BSCriticalSection                  rendererLock;             // 2580
			const char*                        className;                // 25A8
			void*                              instance;                 // 25B0
			bool                               nvapiEnabled;             // 25B8
		};
		static_assert(sizeof(RendererData) == 0x25C0);

		class Renderer
		{
		public:
			using ResetRenderTargets_t = void (*)();

			void IncRef(Buffer* a_vertexBuffer)
			{
				using func_t = decltype(&BSGraphics::Renderer::IncRef);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::IncRef };
				return func(this, a_vertexBuffer);
			}

			void DecRef(Buffer* a_vertexBuffer)
			{
				using func_t = decltype(&BSGraphics::Renderer::DecRef);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::DecRef };
				return func(this, a_vertexBuffer);
			}

			void Begin(std::uint32_t a_windowID)
			{
				using func_t = decltype(&BSGraphics::Renderer::Begin);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::Begin };
				return func(this, a_windowID);
			}

			void End()
			{
				using func_t = decltype(&BSGraphics::Renderer::End);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::End };
				return func(this);
			}

			void Lock()
			{
				using func_t = decltype(&BSGraphics::Renderer::Lock);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::Lock };
				return func(this);
			}

			void Unlock()
			{
				using func_t = decltype(&BSGraphics::Renderer::Unlock);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::Unlock };
				return func(this);
			}

			// Saves one previous color for restore; calls do not nest.
			void SetClearColor(float a_red, float a_green, float a_blue, float a_alpha)
			{
				using func_t = decltype(&BSGraphics::Renderer::SetClearColor);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::SetClearColor };
				return func(this, a_red, a_green, a_blue, a_alpha);
			}

			[[nodiscard]] ConstantGroup* GetShaderConstantGroup(PixelShader* a_shader, std::uint32_t a_level)
			{
				using func_t = decltype(&BSGraphics::Renderer::GetShaderConstantGroup);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::GetShaderConstantGroupPS };
				return func(this, a_shader, a_level);
			}

			void ResetState()
			{
				using func_t = decltype(&BSGraphics::Renderer::ResetState);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::ResetState };
				return func(this);
			}

			void WindowSizeChanged(std::uint32_t a_windowID)
			{
				using func_t = decltype(&BSGraphics::Renderer::WindowSizeChanged);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::WindowSizeChanged };
				return func(this, a_windowID);
			}

			void DoZPrePass(NiCamera* a_worldCamera, NiCamera* a_firstPersonCamera, float a_worldParam0, float a_worldParam1, float a_firstPersonParam0, float a_firstPersonParam1)
			{
				using func_t = decltype(&BSGraphics::Renderer::DoZPrePass);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::DoZPrePass };
				return func(this, a_worldCamera, a_firstPersonCamera, a_worldParam0, a_worldParam1, a_firstPersonParam0, a_firstPersonParam1);
			}

			void ResetWindow(std::uint32_t a_windowID)
			{
				using func_t = decltype(&BSGraphics::Renderer::ResetWindow);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::ResetWindow };
				return func(this, a_windowID);
			}

			void SetShaders(VertexShader* a_vertexShader, HullShader* a_hullShader, DomainShader* a_domainShader, PixelShader* a_pixelShader)
			{
				using func_t = decltype(&BSGraphics::Renderer::SetShaders);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::SetShaders };
				return func(this, a_vertexShader, a_hullShader, a_domainShader, a_pixelShader);
			}

			void DrawTriShape(TriShape* a_shape, std::uint32_t a_startIndex, std::uint32_t a_numTriangles)
			{
				using func_t = decltype(&BSGraphics::Renderer::DrawTriShape);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::DrawTriShape };
				return func(this, a_shape, a_startIndex, a_numTriangles);
			}

			// A null index buffer draws with the shape's own.
			void DrawTriShapeIndexed(TriShape* a_shape, std::uint32_t a_startIndex, std::uint32_t a_numTriangles, IndexBuffer* a_indexBuffer)
			{
				using func_t = decltype(&BSGraphics::Renderer::DrawTriShapeIndexed);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::DrawTriShapeIndexed };
				return func(this, a_shape, a_startIndex, a_numTriangles, a_indexBuffer);
			}

			void DrawTriShapeLargeIndices(TriShape* a_shape, std::uint32_t a_startIndex, std::uint32_t a_numTriangles)
			{
				using func_t = decltype(&BSGraphics::Renderer::DrawTriShapeLargeIndices);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::DrawTriShapeLargeIndices };
				return func(this, a_shape, a_startIndex, a_numTriangles);
			}

			// A non-null instance buffer binds as the second vertex stream.
			void DrawInstancedTriShape(TriShape* a_shape, std::uint32_t a_startIndex, std::uint32_t a_numTriangles, std::uint32_t a_instanceCount, std::uint64_t a_vertexDesc, VertexBuffer* a_instanceBuffer)
			{
				using func_t = decltype(&BSGraphics::Renderer::DrawInstancedTriShape);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::DrawInstancedTriShape };
				return func(this, a_shape, a_startIndex, a_numTriangles, a_instanceCount, a_vertexDesc, a_instanceBuffer);
			}

			void DrawDynamicTriShape(DynamicTriShape* a_shape, DynamicTriShapeDrawData& a_drawData, std::uint32_t a_startIndex, std::uint32_t a_numTriangles, IndexBuffer* a_indexBuffer)
			{
				using func_t = decltype(&BSGraphics::Renderer::DrawDynamicTriShape);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::DrawDynamicTriShape };
				return func(this, a_shape, a_drawData, a_startIndex, a_numTriangles, a_indexBuffer);
			}

			void DrawParticleShaderTriShape(const void* a_vertices, std::uint32_t a_vertexCount)
			{
				using func_t = decltype(&BSGraphics::Renderer::DrawParticleShaderTriShape);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::DrawParticleShaderTriShape };
				return func(this, a_vertices, a_vertexCount);
			}

			void ProcessCommandBuffer(char** a_records)
			{
				using func_t = decltype(&BSGraphics::Renderer::ProcessCommandBuffer);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::ProcessCommandBuffer };
				return func(this, a_records);
			}

			void RunComputeShader(ComputeShader* a_computeShader, std::uint32_t a_groupCountX, std::uint32_t a_groupCountY, std::uint32_t a_groupCountZ)
			{
				using func_t = decltype(&BSGraphics::Renderer::RunComputeShader);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::RunComputeShader };
				return func(this, a_computeShader, a_groupCountX, a_groupCountY, a_groupCountZ);
			}

			// A zero count uploads the buffer's full capacity.
			void UpdateStructuredBuffer(StructuredBuffer* a_buffer, const void* a_source, std::uint32_t a_stride, std::uint32_t a_count)
			{
				using func_t = decltype(&BSGraphics::Renderer::UpdateStructuredBuffer);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Renderer::UpdateStructuredBuffer };
				return func(this, a_buffer, a_source, a_stride, a_count);
			}

			// members
			bool                 skipNextPresent;     // 00
			ResetRenderTargets_t resetRenderTargets;  // 08
			RendererData         data;                // 10
		};
		static_assert(sizeof(Renderer) == 0x25D0);

		// Submits pending state; output-only skips IA and shader-stage slots.
		inline void SetDirtyStates(bool a_outputStateOnly, bool a_compute)
		{
			using func_t = decltype(&SetDirtyStates);
			static REL::Relocation<func_t> func{ ID::BSGraphics::SetDirtyStates };
			func(a_outputStateOnly, a_compute);
		}

		[[nodiscard]] inline RendererData* GetRendererData()
		{
			static REL::Relocation<RendererData**> ptr{ ID::BSGraphics::GetRendererData };
			return *ptr;
		}

		[[nodiscard]] inline RendererWindow* GetCurrentRendererWindow()
		{
			static REL::Relocation<RendererWindow**> ptr{ ID::BSGraphics::GetCurrentRendererWindow };
			return *ptr;
		}

		class ZPrePassDrawData
		{
		public:
			// members
			TriShape*          shape;          // 00
			const NiTransform* world;          // 08
			std::byte          pad10[0x8];     // 10
			std::uint32_t      indexCount;     // 18
			std::uint16_t      cullMode;       // 1C
			std::uint16_t      depthBiasMode;  // 1E
		};
		static_assert(sizeof(ZPrePassDrawData) == 0x20);

		inline void RenderZPrePass(RendererShadowState& a_state, ZPrePassDrawData& a_data, std::uint64_t& a_vertexDesc, std::uint16_t& a_cullMode, std::uint16_t& a_depthBiasMode)
		{
			using func_t = decltype(&RenderZPrePass);
			static REL::Relocation<func_t> func{ ID::BSGraphics::RenderZPrePass };
			func(a_state, a_data, a_vertexDesc, a_cullMode, a_depthBiasMode);
		}

		inline void RenderAlphaTestZPrePass(RendererShadowState& a_state, AlphaTestZPrePassDrawData& a_data, std::uint64_t& a_vertexDesc, std::uint16_t& a_cullMode, std::uint16_t& a_depthBiasMode, std::uint64_t& a_samplerState)
		{
			using func_t = decltype(&RenderAlphaTestZPrePass);
			static REL::Relocation<func_t> func{ ID::BSGraphics::RenderAlphaTestZPrePass };
			func(a_state, a_data, a_vertexDesc, a_cullMode, a_depthBiasMode, a_samplerState);
		}

		class Context
		{
		public:
			// members
			REX::W32::ID3D11DeviceContext*                          deferredContext;                           // 0000
			REX::W32::ID3D11Buffer*                                 shaderConstantBuffer[541];                 // 0008
			REX::W32::ID3D11Buffer*                                 vertexShaderConstantBufferTechnique[20];   // 10F0
			REX::W32::ID3D11Buffer*                                 vertexShaderConstantBufferMaterial[10];    // 1190
			REX::W32::ID3D11Buffer*                                 vertexShaderConstantBufferGeometry[28];    // 11E0
			REX::W32::ID3D11Buffer*                                 hullShaderConstantBufferTechnique[20];     // 12C0
			REX::W32::ID3D11Buffer*                                 hullShaderConstantBufferMaterial[10];      // 1360
			REX::W32::ID3D11Buffer*                                 hullShaderConstantBufferGeometry[20];      // 13B0
			REX::W32::ID3D11Buffer*                                 domainShaderConstantBufferTechnique[20];   // 1450
			REX::W32::ID3D11Buffer*                                 domainShaderConstantBufferMaterial[10];    // 14F0
			REX::W32::ID3D11Buffer*                                 domainShaderConstantBufferGeometry[20];    // 1540
			REX::W32::ID3D11Buffer*                                 pixelShaderConstantBufferTechnique[36];    // 15E0
			REX::W32::ID3D11Buffer*                                 pixelShaderConstantBufferMaterial[20];     // 1700
			REX::W32::ID3D11Buffer*                                 pixelShaderConstantBufferGeometry[40];     // 17A0
			REX::W32::ID3D11Buffer*                                 computeShaderConstantBufferTechnique[20];  // 18E0
			REX::W32::ID3D11Buffer*                                 computeShaderConstantBufferMaterial[20];   // 1980
			REX::W32::ID3D11Buffer*                                 computeShaderConstantBufferGeometry[34];   // 1A20
			REX::W32::ID3D11Buffer*                                 alphaTestConstantBuffer;                   // 1B30
			REX::W32::ID3D11Buffer*                                 perFrameConstantBuffer;                    // 1B38
			REX::W32::ID3D11Buffer*                                 computeConstantBuffer;                     // 1B40
			REX::W32::ID3D11Buffer*                                 instanceTransformConstantBuffer;           // 1B48
			ConstantGroup                                           miscConstantGroup;                         // 1B50
			RendererShadowState                                     shadowState;                               // 1B70
			RendererShadowState                                     lastDrawCallShadowState;                   // 2480
			REX::W32::ID3D11Buffer*                                 dynamicVertexBuffer[8];                    // 2D90
			REX::W32::ID3D11Query*                                  dynamicVertexBufferAvailQuery[8];          // 2DD0
			std::int32_t                                            dynamicVertexBufferAvail[8];               // 2E10
			std::uint32_t                                           currentDynamicVertexBuffer;                // 2E30
			std::uint32_t                                           currentDynamicVertexBufferOffset;          // 2E34
			REX::W32::ID3D11Buffer*                                 sharedParticleIndexBuffer;                 // 2E38
			REX::W32::ID3D11Buffer*                                 sharedParticleStaticBuffer;                // 2E40
			ConstantGroup                                           vertexConstantBuffersA[3];                 // 2E48
			ConstantGroup                                           pixelConstantBuffersA[3];                  // 2E90
			ConstantGroup                                           domainConstantBuffersA[3];                 // 2ED8
			ConstantGroup                                           hullConstantBuffersA[3];                   // 2F20
			ConstantGroup                                           computeConstantBuffersA[3];                // 2F68
			BSTHashMap<std::uint64_t, REX::W32::ID3D11InputLayout*> inputLayoutMap;                            // 2FB0
			REX::W32::ID3D11InputLayout*                            particleShaderInputLayout;                 // 2FE0
		};
		static_assert(sizeof(Context) == 0x2FF0);

		// Fallback the engine uses when the thread has no installed context.
		[[nodiscard]] inline Context* GetGlobalContext()
		{
			static REL::Relocation<Context**> ptr{ ID::BSGraphics::GlobalContext };
			return *ptr;
		}

		class Vertex
		{
		public:
			enum Attribute : std::uint8_t
			{
				VA_POSITION = 0x0,
				VA_TEXCOORD0 = 0x1,
				VA_TEXCOORD1 = 0x2,
				VA_NORMAL = 0x3,
				VA_BINORMAL = 0x4,
				VA_COLOR = 0x5,
				VA_SKINNING = 0x6,
				VA_LANDDATA = 0x7,
				VA_EYEDATA = 0x8,

				VA_COUNT = 0X9
			};

			enum Flags : std::uint16_t
			{
				VF_VERTEX = 1 << VA_POSITION,
				VF_UV = 1 << VA_TEXCOORD0,
				VF_UV_2 = 1 << VA_TEXCOORD1,
				VF_NORMAL = 1 << VA_NORMAL,
				VF_TANGENT = 1 << VA_BINORMAL,
				VF_COLORS = 1 << VA_COLOR,
				VF_SKINNED = 1 << VA_SKINNING,
				VF_LANDDATA = 1 << VA_LANDDATA,
				VF_EYEDATA = 1 << VA_EYEDATA,
				VF_FULLPREC = 0x400
			};

			enum Masks : std::uint64_t
			{
				DESC_MASK_VERT = 0xFFFFFFFFFFFFFFF0,
				DESC_MASK_UVS = 0xFFFFFFFFFFFFFF0F,
				DESC_MASK_NBT = 0xFFFFFFFFFFFFF0FF,
				DESC_MASK_SKCOL = 0xFFFFFFFFFFFF0FFF,
				DESC_MASK_DATA = 0xFFFFFFFFFFF0FFFF,
				DESC_MASK_OFFSET = 0xFFFFFF0000000000,
				DESC_MASK_FLAGS = ~(DESC_MASK_OFFSET)
			};
		};

		class VertexDesc
		{
		public:
			[[nodiscard]] bool HasFlag(Vertex::Flags a_flag) const
			{
				return ((desc >> 44) & a_flag) != 0;
			}

			void SetFlag(Vertex::Flags a_flag)
			{
				desc |= (static_cast<uint64_t>(a_flag) << 44);
			}

			void ClearFlag(Vertex::Flags a_flag)
			{
				desc &= ~(static_cast<uint64_t>(a_flag) << 44);
			}

			[[nodiscard]] std::uint32_t GetAttributeOffset(Vertex::Attribute a_attribute) const
			{
				return (desc >> (4 * static_cast<uint8_t>(a_attribute) + 2)) & 0x3C;
			}

			void SetAttributeOffset(Vertex::Attribute a_attribute, std::uint32_t a_offset)
			{
				if (a_attribute != Vertex::Attribute::VA_POSITION) {
					const uint64_t lhs = static_cast<uint64_t>(a_offset) << (4 * static_cast<uint8_t>(a_attribute) + 2);
					const uint64_t rhs = desc & ~static_cast<uint64_t>(15 << (4 * static_cast<uint8_t>(a_attribute) + 4));

					desc = lhs | rhs;
				}
			}

			void ClearAttributeOffsets()
			{
				desc &= Vertex::Masks::DESC_MASK_OFFSET;
			}

			[[nodiscard]] Vertex::Flags GetFlags() const
			{
				return static_cast<Vertex::Flags>((desc & Vertex::Masks::DESC_MASK_OFFSET) >> 44);
			}

			void SetFlags(Vertex::Flags a_flags)
			{
				desc |= (static_cast<uint64_t>(a_flags) << 44) | (desc & Vertex::Masks::DESC_MASK_FLAGS);
			}

			[[nodiscard]] std::uint32_t GetSize()
			{
				return (desc & 0xF) * 4;
			}

			// members
			std::uint64_t desc;  // 00
		};
		static_assert(sizeof(VertexDesc) == 0x8);

		class TriShape
		{
		public:
			VertexDesc    vertexDesc;    // 00
			VertexBuffer* vertexBuffer;  // 08
			IndexBuffer*  indexBuffer;   // 10
			std::uint32_t uiRefCount;    // 18
		};
		static_assert(sizeof(TriShape) == 0x20);

		class FogStateType
		{
		public:
			// members
			NiPoint4 rangeData;         // 00
			NiColor  nearLowColor;      // 10
			float    power;             // 1C
			NiColor  nearHighColor;     // 20
			float    clamp;             // 2C
			NiColor  farLowColor;       // 30
			float    highDensityScale;  // 3C
			NiColor  farHighColor;      // 40
			float    padding;           // 4C
			NiPoint4 highLowRangeData;  // 50
		};
		static_assert(sizeof(FogStateType) == 0x60);

		class CameraStateData
		{
		public:
			// members
			ViewData        camViewData;        // 000
			NiPoint3        posAdjust;          // 210
			NiPoint3        currentPosAdjust;   // 21C
			NiPoint3        previousPosAdjust;  // 228
			const NiCamera* referenceCamera;    // 238
			bool            useJitter;          // 240
		};
		static_assert(sizeof(CameraStateData) == 0x250);

		class State
		{
		public:
			[[nodiscard]] static State* GetSingleton()
			{
				static REL::Relocation<State*> singleton{ ID::BSGraphics::State::Singleton };
				return singleton.get();
			}

			void UpdateTemporalData()
			{
				using func_t = decltype(&BSGraphics::State::UpdateTemporalData);
				static REL::Relocation<func_t> func{ ID::BSGraphics::State::UpdateTemporalData };
				return func(this);
			}

			// members
			std::uint32_t             currentFrame;                      // 000
			float                     offsetX;                           // 004
			float                     offsetY;                           // 008
			std::uint32_t             currentFrameOffset;                // 00C
			std::uint32_t             previousFrameOffset;               // 010
			FogStateType              fogState;                          // 014
			MultiSampleLevel          multiSample;                       // 074
			std::uint32_t             backBufferWidth;                   // 078
			std::uint32_t             backBufferHeight;                  // 07C
			std::uint32_t             screenWidth;                       // 080
			std::uint32_t             screenHeight;                      // 084
			NiRect<float>             frameBufferViewport;               // 088
			std::uint32_t             frameCount;                        // 098
			std::uint32_t             frameID;                           // 09C
			bool                      insideFrame;                       // 0A0
			bool                      letterbox;                         // 0A1
			bool                      allowDepthBufferAsTexture;         // 0A2
			bool                      shadows;                           // 0A3
			bool                      compiledShaderThisFrame;           // 0A4
			std::byte                 pad0A5[0x7];                       // 0A5
			TAA_STATE                 taaState;                          // 0AC
			std::uint32_t             taaDisableCounter;                 // 0B0
			std::uint32_t             trijuiceState;                     // 0B4
			NiPointer<NiTexture>      defaultTextureBlack;               // 0B8
			NiPointer<NiTexture>      defaultTextureWhite;               // 0C0
			NiPointer<NiTexture>      defaultTextureGrey;                // 0C8
			NiPointer<NiTexture>      defaultHeightMap;                  // 0D0
			NiPointer<NiTexture>      defaultReflectionCubeMap;          // 0D8
			NiPointer<NiTexture>      defaultFaceDetailMap;              // 0E0
			NiPointer<NiTexture>      defaultHighFreqNormalMap;          // 0E8
			NiPointer<NiTexture>      defaultTexEffectMap;               // 0F0
			NiPointer<NiTexture>      defaultTextureWhiteNoiseMap;       // 0F8
			NiPointer<NiTexture>      defaultTextureWhiteNoiseMapSmall;  // 100
			NiPointer<NiTexture>      defaultTextureNormalMap;           // 108
			NiPointer<NiTexture>      defaultTextureDiffuseMap;          // 110
			NiPointer<NiTexture>      defaultSplineMap;                  // 118
			NiPointer<NiTexture>      defaultTextureDissolvePattern;     // 120
			Texture*                  defaultImagespaceLUT;              // 128
			NiPointer<NiTexture>      rotatedPoissonDiscLookupMap;       // 130
			std::uint32_t             presentImmediateThreshold;         // 138
			std::uint32_t             presentFlag;                       // 13C
			BSTArray<CameraStateData> cameraDataCache;                   // 140
			CameraStateData           cameraState;                       // 160
			bool                      commitTexturesOnCreation;          // 3B0
			bool                      immediateTextureLoads;             // 3B1
		};
		static_assert(sizeof(State) == 0x3C0);

		class RenderTargetProperties
		{
		public:
			// members
			std::uint32_t width;                   // 00
			std::uint32_t height;                  // 04
			Format        format;                  // 08
			std::uint32_t multiSample;             // 0C
			bool          copyable;                // 10
			bool          supportUnorderedAccess;  // 11
			bool          allowMipGeneration;      // 12
			bool          forceLinear;             // 13
			std::int32_t  mipLevel;                // 14
			std::uint32_t textureTarget;           // 18
			bool          enableFastClear;         // 1C
		};
		static_assert(sizeof(RenderTargetProperties) == 0x20);

		class DepthStencilTargetProperties
		{
		public:
			// members
			std::uint32_t width;           // 00
			std::uint32_t height;          // 04
			std::uint32_t arraySize;       // 08
			std::uint32_t multiSample;     // 0C
			std::int32_t  alias;           // 10
			bool          sampleable;      // 14
			bool          htile;           // 15
			bool          stencil;         // 16
			bool          use16BitsDepth;  // 17
			std::byte     pad18[0x4];      // 18
		};
		static_assert(sizeof(DepthStencilTargetProperties) == 0x1C);

		class CubeMapRenderTargetProperties
		{
		public:
			// members
			std::uint32_t width;           // 00
			std::uint32_t height;          // 04
			Format        format;          // 08
			std::uint32_t multiSample;     // 0C
			bool          sampleable;      // 10
			std::int32_t  alias;           // 14
			std::int32_t  _360Alias;       // 18
			std::int32_t  _360Group;       // 1C
			std::int32_t  _360TileHeight;  // 20
		};
		static_assert(sizeof(CubeMapRenderTargetProperties) == 0x24);

		class DynamicTriShapeData
		{
		public:
			// members
			VertexBuffer* vb;          // 00
			std::uint32_t dataStride;  // 08
		};
		static_assert(sizeof(DynamicTriShapeData) == 0x10);

		class DynamicTriShapeDrawData
		{
		public:
			// members
			REX::W32::ID3D11Buffer* buffer;  // 00
			std::uint32_t           offset;  // 08
		};
		static_assert(sizeof(DynamicTriShapeDrawData) == 0x10);

		class RenderTargetManager
		{
		public:
			using Create_T = void (*)();

			[[nodiscard]] static RenderTargetManager* GetSingleton()
			{
				static REL::Relocation<RenderTargetManager*> singleton{ ID::BSGraphics::RenderTargetManager::Singleton };
				return singleton.get();
			}

			void UpdateDynamicResolution(const NiPoint3* a_position, const NiPoint3* a_previousPosition, const NiPoint3* a_direction, const NiPoint3* a_previousDirection)
			{
				using func_t = decltype(&RenderTargetManager::UpdateDynamicResolution);
				static REL::Relocation<func_t> func{ ID::BSGraphics::RenderTargetManager::UpdateDynamicResolution };
				return func(this, a_position, a_previousPosition, a_direction, a_previousDirection);
			}

			void SetEnableDynamicResolution(bool a_enableDynamicResolution)
			{
				using func_t = decltype(&RenderTargetManager::SetEnableDynamicResolution);
				static REL::Relocation<func_t> func{ ID::BSGraphics::RenderTargetManager::SetEnableDynamicResolution };
				return func(this, a_enableDynamicResolution);
			}

			void CreateRenderTarget(RenderTargetID a_logicalID, const RenderTargetProperties* a_properties, RenderTargetCreationMode a_mode)
			{
				using func_t = decltype(&RenderTargetManager::CreateRenderTarget);
				static REL::Relocation<func_t> func{ ID::BSGraphics::RenderTargetManager::CreateRenderTarget };
				return func(this, a_logicalID, a_properties, a_mode);
			}

			void CreateDepthStencilTarget(DepthStencilTargetID a_logicalID, const DepthStencilTargetProperties* a_properties, RenderTargetCreationMode a_mode)
			{
				using func_t = decltype(&RenderTargetManager::CreateDepthStencilTarget);
				static REL::Relocation<func_t> func{ ID::BSGraphics::RenderTargetManager::CreateDepthStencilTarget };
				return func(this, a_logicalID, a_properties, a_mode);
			}

			void CreateCubeMapRenderTarget(CubeMapRenderTargetID a_logicalID, const CubeMapRenderTargetProperties* a_properties, RenderTargetCreationMode a_mode)
			{
				using func_t = decltype(&RenderTargetManager::CreateCubeMapRenderTarget);
				static REL::Relocation<func_t> func{ ID::BSGraphics::RenderTargetManager::CreateCubeMapRenderTarget };
				return func(this, a_logicalID, a_properties, a_mode);
			}

			[[nodiscard]] static std::uint32_t QShadowMapArrayDepthStencil()
			{
				using func_t = decltype(&RenderTargetManager::QShadowMapArrayDepthStencil);
				static REL::Relocation<func_t> func{ ID::BSGraphics::RenderTargetManager::QShadowMapArrayDepthStencil };
				return func();
			}

			void SetUseDynamicResolutionViewportAsDefaultViewport(bool a_useDynamicResolutionViewport)
			{
				using func_t = decltype(&RenderTargetManager::SetUseDynamicResolutionViewportAsDefaultViewport);
				static REL::Relocation<func_t> func{ ID::BSGraphics::RenderTargetManager::SetUseDynamicResolutionViewportAsDefaultViewport };
				return func(this, a_useDynamicResolutionViewport);
			}

			// A logical ID of -1 unbinds the slot.
			void SetCurrentRenderTarget(std::int32_t a_slot, std::int32_t a_logicalID, SetRenderTargetMode a_mode)
			{
				using func_t = decltype(&RenderTargetManager::SetCurrentRenderTarget);
				static REL::Relocation<func_t> func{ ID::BSGraphics::RenderTargetManager::SetCurrentRenderTarget };
				return func(this, a_slot, a_logicalID, a_mode);
			}

			// Binds a pooled target as a PS texture; a_useCopy picks its copy view.
			void SetTextureRenderTarget(std::uint32_t a_slot, std::int32_t a_logicalID, TextureAddressMode a_mode, bool a_useCopy)
			{
				using func_t = decltype(&RenderTargetManager::SetTextureRenderTarget);
				static REL::Relocation<func_t> func{ ID::BSGraphics::RenderTargetManager::SetTextureRenderTarget };
				return func(this, a_slot, a_logicalID, a_mode, a_useCopy);
			}

			void SetCurrentCubeMapRenderTarget(std::int32_t a_logicalID, SetRenderTargetMode a_mode, std::int32_t a_face)
			{
				using func_t = decltype(&RenderTargetManager::SetCurrentCubeMapRenderTarget);
				static REL::Relocation<func_t> func{ ID::BSGraphics::RenderTargetManager::SetCurrentCubeMapRenderTarget };
				return func(this, a_logicalID, a_mode, a_face);
			}

			void AcquireRenderTarget(std::int32_t a_logicalID)
			{
				using func_t = decltype(&RenderTargetManager::AcquireRenderTarget);
				static REL::Relocation<func_t> func{ ID::BSGraphics::RenderTargetManager::AcquireRenderTarget };
				return func(this, a_logicalID);
			}

			void ReleaseRenderTarget(std::int32_t a_logicalID)
			{
				using func_t = decltype(&RenderTargetManager::ReleaseRenderTarget);
				static REL::Relocation<func_t> func{ ID::BSGraphics::RenderTargetManager::ReleaseRenderTarget };
				return func(this, a_logicalID);
			}

			static void SetCurrentViewportForceToRenderTargetDimensions()
			{
				using func_t = decltype(&RenderTargetManager::SetCurrentViewportForceToRenderTargetDimensions);
				static REL::Relocation<func_t> func{ ID::BSGraphics::RenderTargetManager::SetCurrentViewportForceToRenderTargetDimensions };
				return func();
			}

			// members
			RenderTargetProperties        renderTargetData[100];                          // 000
			DepthStencilTargetProperties  depthStencilTargetData[12];                     // C80
			CubeMapRenderTargetProperties cubeMapRenderTargetData[1];                     // DD0
			std::uint32_t                 renderTargetID[100];                            // DF4
			std::uint32_t                 depthStencilTargetID[12];                       // F84
			std::uint32_t                 cubeMapRenderTargetID[1];                       // FB4
			float                         dynamicWidthRatio;                              // FB8
			float                         dynamicHeightRatio;                             // FBC
			float                         lowestWidthRatio;                               // FC0
			float                         lowestHeightRatio;                              // FC4
			float                         ratioIncreasePerSeconds;                        // FC8
			float                         ratioDecreasePerSeconds;                        // FCC
			std::uint32_t                 nbFramePause;                                   // FD0
			std::uint32_t                 nbFramesSinceLastIncrease;                      // FD4
			float                         forcedRatio;                                    // FD8
			float                         movementDelta;                                  // FDC
			bool                          increaseResolution;                             // FE0
			bool                          freezeResolution;                               // FE1
			bool                          toggledOff;                                     // FE2
			bool                          updateResolutionOnlyWhenMoving;                 // FE3
			bool                          useDynamicResolutionViewportAsDefaultViewport;  // FE4
			bool                          isDynamicResolutionCurrentlyActivated;          // FE5
			BSTAtomicValue<std::uint32_t> dynamicResolutionDisabled;                      // FE8
			Create_T                      create;                                         // FF0
		};
		static_assert(sizeof(RenderTargetManager) == 0xFF8);

		class OcclusionQuery
		{
		public:
			// members
			REX::W32::ID3D11Query* occlusionQuery;  // 00
			std::uint32_t          inUse;           // 08
		};
		static_assert(sizeof(OcclusionQuery) == 0x10);

		namespace Utility
		{
			inline void ConvertHALFToNiPoint3Stream(const std::uint16_t* a_src, NiPoint3* a_dst, std::uint32_t a_count, std::uint32_t a_stride)
			{
				using func_t = decltype(&ConvertHALFToNiPoint3Stream);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Utility::ConvertHALFToNiPoint3Stream };
				func(a_src, a_dst, a_count, a_stride);
			}

			inline void ConvertNiPoint3ToHALFStream(const NiPoint3* a_src, std::uint16_t* a_dst, std::uint32_t a_count)
			{
				using func_t = decltype(&ConvertNiPoint3ToHALFStream);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Utility::ConvertNiPoint3ToHALFStream };
				func(a_src, a_dst, a_count);
			}

			inline std::uint64_t PackVertexData(
				std::uint32_t  a_numVertices,
				NiPoint3*      a_positions,
				NiPoint2*      a_texCoords0,
				NiColorA*      a_texCoords1,
				NiPoint3*      a_normals,
				NiPoint3*      a_binormals,
				NiPoint3*      a_tangents,
				NiColorA*      a_colors,
				NiColorA*      a_skinBoneWeights,
				std::uint8_t*  a_skinBoneIndices,
				NiColorA*      a_landscapeData1,
				NiColorA*      a_landscapeData2,
				float*         a_eyeData,
				void*          a_buffer,
				std::uint32_t* a_bufferSize,
				std::uint16_t* a_vertexMap,
				std::uint32_t  a_dynamicFlags,
				std::uint16_t* a_tangentXBuffer,
				std::uint32_t  a_tangentXBufferStride)
			{
				using func_t = decltype(&PackVertexData);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Utility::PackVertexData };
				return func(a_numVertices, a_positions, a_texCoords0, a_texCoords1, a_normals, a_binormals, a_tangents, a_colors, a_skinBoneWeights, a_skinBoneIndices, a_landscapeData1, a_landscapeData2, a_eyeData, a_buffer, a_bufferSize, a_vertexMap, a_dynamicFlags, a_tangentXBuffer, a_tangentXBufferStride);
			}

			inline void UnpackVertexData(
				const std::uint8_t* a_vertices,
				const std::uint16_t a_index,
				const std::uint64_t a_vertexDesc,
				NiPoint3*           a_position,
				NiPoint2*           a_texCoord0,
				NiPoint2*           a_texCoord1,
				NiPoint3*           a_normal,
				NiPoint3*           a_binormal,
				NiPoint3*           a_tangent,
				NiColorA*           a_color,
				NiColorA*           a_skinBoneWeights,
				std::uint8_t*       a_boneIndex0,
				std::uint8_t*       a_boneIndex1,
				std::uint8_t*       a_boneIndex2,
				std::uint8_t*       a_boneIndex3)
			{
				using func_t = decltype(&UnpackVertexData);
				static REL::Relocation<func_t> func{ ID::BSGraphics::Utility::UnpackVertexData };
				func(a_vertices, a_index, a_vertexDesc, a_position, a_texCoord0, a_texCoord1, a_normal, a_binormal, a_tangent, a_color, a_skinBoneWeights, a_boneIndex0, a_boneIndex1, a_boneIndex2, a_boneIndex3);
			}
		}
	}
}
