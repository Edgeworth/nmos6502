#ifndef NMOS6502_INSTRUCTIONS_HPP_
#define NMOS6502_INSTRUCTIONS_HPP_
#include "nmos6502/common.hpp"
#include "nmos6502/cpu.hpp"

namespace nmos6502 {

	typedef int (*Instruction)(CPU&);
	extern Instruction opcodes[]; ///< 256 possible opcodes, 151 of them are implemented

	class InstructionSet {
	public:

	};

}

#endif
