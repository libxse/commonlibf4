#pragma once

#include "RE/B/BSCriticalSection.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTAtomicValue.h"
#include "RE/B/BSTHashMap.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"
#include "RE/N/NiRect.h"
#include "RE/N/NiTexture.h"

#include "REX/W32/D3D11.h"

namespace RE
{
	class BSD3DResourceCreator;
	class BSEventFlag;
	class NiCamera;

	namespace BSGraphics
	{
		enum class Format;
		class Texture;

		enum class MultiSampleLevel
		{
			kNone,
			kTwo,
			kFour,
			kEight
		};

		enum class SetRenderTargetMode
		{
			kClear = 0x0,
			kClearDepth = 0x1,
			kClearStencil = 0x2,
			kNoClear = 0x3,
			kRestore = 0x3,
			kForceCopyRestore = 0x4,
			kInit = 0x5
		};

		enum class TAA_STATE
		{
			kDisabled,
			kEnabled
		};

		enum class TextureFileFormat
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

		enum class TextureFilterMode
		{
			kNearest = 0x0,
			kBilerp = 0x1,
			kTrilerp = 0x2,
			kAniso = 0x3,
			kCompBilerp = 0x4,
		};

		enum class TextureAddressMode
		{
			kClamp_S_Clamp_T = 0x0,
			kClamp_S_Wrap_T = 0x1,
			kWrap_S_Clamp_T = 0x2,
			kWrap_S_Wrap_T = 0x3,
		};

		enum class Usage
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

		class TextureHeader
		{
		public:
			// members
			std::uint16_t height = 0;    // 0
			std::uint16_t width = 0;     // 2
			std::uint8_t  mipCount = 0;  // 3
			std::uint8_t  format = 0;    // 5
			std::uint8_t  flags = 0;     // 6
			std::uint8_t  tilemode = 0;  // 7
		};
		static_assert(sizeof(TextureHeader) == 0x8);

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
			std::uint32_t                 id{ 0 };                  // 00
			REX::W32::ID3D11DomainShader* shader{ nullptr };        // 08
			std::uint32_t                 byteCodeSize{ 0 };        // 10
			BSGraphics::ConstantGroup     constantBuffers[3]{ 0 };  // 18
			std::uint64_t                 shaderDesc{ 0 };          // 60
			std::int8_t                   constantTable[32]{ 0 };   // 68
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

		class alignas(0x10) RendererShadowState
		{
		public:
			std::byte pad[0x910];  // 000
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

			// members
			bool                 skipNextPresent;     // 00
			ResetRenderTargets_t resetRenderTargets;  // 08
			RendererData         data;                // 10
		};
		static_assert(sizeof(Renderer) == 0x25D0);

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
			[[nodiscard]] static State GetSingleton()
			{
				static REL::Relocation<State*> singleton{ ID::BSGraphics::State::Singleton };
				return *singleton;
			}

			// members
			std::uint32_t                                 currentFrame;                      // 000
			float                                         offsetX;                           // 004
			float                                         offsetY;                           // 008
			std::uint32_t                                 currentFrameOffset;                // 00C
			std::uint32_t                                 previousFrameOffset;               // 010
			FogStateType                                  fogState;                          // 014
			REX::EnumSet<MultiSampleLevel, std::uint32_t> multiSample;                       // 074
			std::uint32_t                                 backBufferWidth;                   // 078
			std::uint32_t                                 backBufferHeight;                  // 07C
			std::uint32_t                                 screenWidth;                       // 080
			std::uint32_t                                 screenHeight;                      // 084
			NiRect<float>                                 frameBufferViewport;               // 088
			std::uint32_t                                 frameCount;                        // 098
			std::uint32_t                                 frameID;                           // 09C
			bool                                          insideFrame;                       // 0A0
			bool                                          letterbox;                         // 0A1
			bool                                          allowDepthBufferAsTexture;         // 0A2
			bool                                          shadows;                           // 0A3
			bool                                          compiledShaderThisFrame;           // 0A4
			REX::EnumSet<TAA_STATE, std::uint32_t>        taaState;                          // 0A8
			std::uint32_t                                 taaDisableCounter;                 // 0AC
			std::uint32_t                                 trijuiceState;                     // 0B0
			NiPointer<NiTexture>                          defaultTextureBlack;               // 0B8
			NiPointer<NiTexture>                          defaultTextureWhite;               // 0C0
			NiPointer<NiTexture>                          defaultTextureGrey;                // 0C8
			NiPointer<NiTexture>                          defaultHeightMap;                  // 0D0
			NiPointer<NiTexture>                          defaultReflectionCubeMap;          // 0D8
			NiPointer<NiTexture>                          defaultFaceDetailMap;              // 0E0
			NiPointer<NiTexture>                          defaultHighFreqNormalMap;          // 0E8
			NiPointer<NiTexture>                          defaultTexEffectMap;               // 0F0
			NiPointer<NiTexture>                          defaultTextureWhiteNoiseMap;       // 0F8
			NiPointer<NiTexture>                          defaultTextureWhiteNoiseMapSmall;  // 100
			NiPointer<NiTexture>                          defaultTextureNormalMap;           // 108
			NiPointer<NiTexture>                          defaultTextureDiffuseMap;          // 110
			NiPointer<NiTexture>                          defaultSplineMap;                  // 118
			NiPointer<NiTexture>                          defaultTextureDissolvePattern;     // 120
			Texture*                                      defaultImagespaceLUT;              // 128
			NiPointer<NiTexture>                          rotatedPoissonDiscLookupMap;       // 130
			std::uint32_t                                 presentImmediateThreshold;         // 138
			std::uint32_t                                 presentFlag;                       // 13C
			BSTArray<CameraStateData>                     cameraDataCache;                   // 140
			CameraStateData                               cameraState;                       // 160
			bool                                          commitTexturesOnCreation;          // 3B0
			bool                                          immediateTextureLoads;             // 3B1
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
		};
		static_assert(sizeof(DepthStencilTargetProperties) == 0x18);

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

			[[nodiscard]] static RenderTargetManager GetSingleton()
			{
				static REL::Relocation<RenderTargetManager*> singleton{ ID::BSGraphics::RenderTargetManager::Singleton };
				return *singleton;
			}

			void SetEnableDynamicResolution(bool a_enableDynamicResolution)
			{
				using func_t = decltype(&RenderTargetManager::SetEnableDynamicResolution);
				static REL::Relocation<func_t> func{ ID::BSGraphics::RenderTargetManager::SetEnableDynamicResolution };
				return func(this, a_enableDynamicResolution);
			}

			// members
			RenderTargetProperties        renderTargetData[100];       // 000
			DepthStencilTargetProperties  depthStencilTargetData[12];  // C80
			CubeMapRenderTargetProperties cubeMapRenderTargetData[1];  // DA0
			std::byte                     padDC4[0x30];
			std::uint32_t                 renderTargetID[100];                            // DC4
			std::uint32_t                 depthStencilTargetID[12];                       // F54
			std::uint32_t                 cubeMapRenderTargetID[1];                       // F84
			float                         dynamicWidthRatio;                              // F88
			float                         dynamicHeightRatio;                             // F8C
			float                         lowestWidthRatio;                               // F90
			float                         lowestHeightRatio;                              // F94
			float                         ratioIncreasePerSeconds;                        // F98
			float                         ratioDecreasePerSeconds;                        // F9C
			float                         movementDelta;                                  // FA0
			bool                          increaseResolution;                             // FA4
			bool                          freezeResolution;                               // FA5
			bool                          updateResolutionOnlyWhenMoving;                 // FA6
			bool                          useDynamicResolutionViewportAsDefaultViewport;  // FA7
			bool                          isDynamicResolutionCurrentlyActivated;          // FA8
			std::uint32_t                 nbFramePause;                                   // FAC
			std::uint32_t                 nbFramesSinceLastIncrease;                      // FB0
			BSTAtomicValue<std::uint32_t> dynamicResolutionDisabled;                      // FB4
			Create_T                      create;                                         // FB8
		};
		static_assert(sizeof(RenderTargetManager) == 0xFF0);

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
