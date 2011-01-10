#ifndef NMOS6502_CPU_HPP_
#define NMOS6502_CPP_HPP_
#include "nmos6502/common.hpp"
#include "nmos6502/memory.hpp"

namespace nmos6502 {

	/** \brief This enum is used in conjunction with set, unset and get */
	enum {
		FCARRY,
		FZERO,
		FINT,
		FBCD,
		FBRK,
		FUNUSED,
		FOVER,
		FNEG
	};


	class CPU {
	public:
		int8 A; ///< Accumulator register
		uint8 X; ///< X index register
		uint8 Y; ///< Y index register
		uint8 SP; ///< Stack pointer

		/** \brief Status register.
		 *
		 * Layout:\n
		 * 	7 6 5 4 3 2 1 0\n
		 *	N V - B D I Z C\n
		 * - N: Negative flag
		 * - V: Overflow flag
		 * - B: BRK flag
		 * - D: BCD flag
		 * - I: Interrupt disable flag
		 * - Z: Zero flag
		 * - C: Carry flag
		 */
		uint8 P;
		uint16 PC; ///< Program counter

		long long cycles; ///< Cycles since reset()

		CPU();

		/** \brief Run the cpu for at most \a max_cycles cycles.
		 *
		 * \param max_cycles The number of cycles to run the cpu at most for.
		 *
		 * \return The actual number of cycles executed.
		 * \sa step
		 */
		int run(int max_cycles);

		/** \brief Run the cpu for one instruction.
		 *
		 * \return The number of cycles executed
		 * \sa run
		 */
		int step();

		/** \brief Send the cpu an interrupt.
		 *
		 * This can be masked by the interrupt disable flag,
		 * in which case it will return 0.
		 *
		 * When this is executed the following procedure is observed:
		 * -# The high byte of PC is pushed onto the stack
		 * -# The low byte of the PC is pushed onto the stack
		 * -# The processor status register is pushed onto the stack
		 * -# The PC is set to the irq vector
		 * -# The I flag is set
		 *
		 * \return The number of cycles executed
		 * \sa brk, nmi, reset
		 */
		int irq();

		/** \brief Send the cpu a non-blockable interrupt.
		 *
		 * Equivalent to irq, except it cannot be
		 * blocked by the interrupt disable flag.
		 *
		 * \return The number of cycles executed
		 * \sa brk, irq, reset
		 */
		int nmi();

		/** \brief Reset the cpu. Non-blockable.
		 *
		 * This is called the first time #run or #step is executed.
		 * On the nmos 6502, this is implemented as a hacked brk instruction.
		 *
		 * When this is executed the following procedure is observed:
		 * -# The stack pointer is decremented by 3 (the way reset is implemented on the nmos 6502 causes this)
		 * -# The I and B flags are set
		 * -# The PC is set to the reset vector
		 *
		 * \return The number of cycles executed
		 * \sa brk, irq, nmi
		 */
		int reset();

	private:
	};

}

#endif
