#pragma once

namespace RE
{
	class WorkbenchData
	{
	public:
		enum class Type
		{
			kNone = 0x0,
			kCreateObject = 0x1,
			kWeapons = 0x2,
			kEnchanting = 0x3,
			kEnchantingExperiment = 0x4,
			kAlchemy = 0x5,
			kAlchemyExperiment = 0x6,
			kArmor = 0x7,
			kPowerArmor = 0x8,
			kRobotMod = 0x9
		};

		// members
		REX::TEnumSet<Type, std::int8_t> type;  // 00
	};
	static_assert(sizeof(WorkbenchData) == 0x01);
}
