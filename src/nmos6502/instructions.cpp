#include "nmos6502/instructions.hpp"

namespace nmos6502 {
	Instruction opcodes[1<<8] = {
		InstructionSet::brk_imp,
		InstructionSet::ora_idx,
		NULL,
		NULL,
		NULL,
		InstructionSet::ora_zpg,
		InstructionSet::asl_zpg,
		NULL,
		InstructionSet::php_imp,
		InstructionSet::ora_imm,
		InstructionSet::asl_imp,
		NULL,
		NULL,
		InstructionSet::ora_abs,
		InstructionSet::asl_abs,
		NULL,
		InstructionSet::bpl_rel,
		InstructionSet::ora_idy,
		NULL,
		NULL,
		NULL,
		InstructionSet::ora_zpx,
		InstructionSet::asl_zpx,
		NULL,
		InstructionSet::clc_imp,
		InstructionSet::ora_aby,
		NULL,
		NULL,
		NULL,
		InstructionSet::ora_abx,
		InstructionSet::asl_abx,
		NULL,
		InstructionSet::jsr_abs,
		InstructionSet::and_idx,
		NULL,
		NULL,
		InstructionSet::bit_zpg,
		InstructionSet::and_zpg,
		InstructionSet::rol_zpg,
		NULL,
		InstructionSet::plp_imp,
		InstructionSet::and_imm,
		InstructionSet::rol_imp,
		NULL,
		InstructionSet::bit_abs,
		InstructionSet::and_abs,
		InstructionSet::rol_abs,
		NULL,
		InstructionSet::bmi_rel,
		InstructionSet::and_idy,
		NULL,
		NULL,
		NULL,
		InstructionSet::and_zpx,
		InstructionSet::rol_zpx,
		NULL,
		InstructionSet::sec_imp,
		InstructionSet::and_aby,
		NULL,
		NULL,
		NULL,
		InstructionSet::and_abx,
		InstructionSet::rol_abx,
		NULL,
		InstructionSet::rti_imp,
		InstructionSet::eor_idx,
		NULL,
		NULL,
		NULL,
		InstructionSet::eor_zpg,
		InstructionSet::lsr_zpg,
		NULL,
		InstructionSet::pha_imp,
		InstructionSet::eor_imm,
		InstructionSet::lsr_imp,
		NULL,
		InstructionSet::jmp_abs,
		InstructionSet::eor_abs,
		InstructionSet::lsr_abs,
		NULL,
		InstructionSet::bvc_rel,
		InstructionSet::eor_idy,
		NULL,
		NULL,
		NULL,
		InstructionSet::eor_zpx,
		InstructionSet::lsr_zpx,
		NULL,
		InstructionSet::cli_imp,
		InstructionSet::eor_aby,
		NULL,
		NULL,
		NULL,
		InstructionSet::eor_abx,
		InstructionSet::lsr_abx,
		NULL,
		InstructionSet::rts_imp,
		InstructionSet::adc_idx,
		NULL,
		NULL,
		NULL,
		InstructionSet::adc_zpg,
		InstructionSet::ror_zpg,
		NULL,
		InstructionSet::pla_imp,
		InstructionSet::adc_imm,
		InstructionSet::ror_imp,
		NULL,
		InstructionSet::jmp_ind,
		InstructionSet::adc_abs,
		InstructionSet::ror_abs,
		NULL,
		InstructionSet::bvs_rel,
		InstructionSet::adc_idy,
		NULL,
		NULL,
		NULL,
		InstructionSet::adc_zpx,
		InstructionSet::ror_zpx,
		NULL,
		InstructionSet::sei_imp,
		InstructionSet::adc_aby,
		NULL,
		NULL,
		NULL,
		InstructionSet::adc_abx,
		InstructionSet::ror_abx,
		NULL,
		NULL,
		InstructionSet::sta_idx,
		NULL,
		NULL,
		InstructionSet::sty_zpg,
		InstructionSet::sta_zpg,
		InstructionSet::stx_zpg,
		NULL,
		InstructionSet::dey_imp,
		NULL,
		InstructionSet::txa_imp,
		NULL,
		InstructionSet::sty_abs,
		InstructionSet::sta_abs,
		InstructionSet::stx_abs,
		NULL,
		InstructionSet::bcc_rel,
		InstructionSet::sta_idy,
		NULL,
		NULL,
		InstructionSet::sty_zpx,
		InstructionSet::sta_zpx,
		InstructionSet::stx_zpy,
		NULL,
		InstructionSet::tya_imp,
		InstructionSet::sta_aby,
		InstructionSet::txs_imp,
		NULL,
		NULL,
		InstructionSet::sta_abx,
		NULL,
		NULL,
		InstructionSet::ldy_imm,
		InstructionSet::lda_idx,
		InstructionSet::ldx_imm,
		NULL,
		InstructionSet::ldy_zpg,
		InstructionSet::lda_zpg,
		InstructionSet::ldx_zpg,
		NULL,
		InstructionSet::tay_imp,
		InstructionSet::lda_imm,
		InstructionSet::tax_imp,
		NULL,
		InstructionSet::ldy_abs,
		InstructionSet::lda_abs,
		InstructionSet::ldx_abs,
		NULL,
		InstructionSet::bcs_rel,
		InstructionSet::lda_idy,
		NULL,
		NULL,
		InstructionSet::ldy_zpx,
		InstructionSet::lda_zpx,
		InstructionSet::ldx_zpy,
		NULL,
		InstructionSet::clv_imp,
		InstructionSet::lda_aby,
		InstructionSet::tsx_imp,
		NULL,
		InstructionSet::ldy_abx,
		InstructionSet::lda_abx,
		InstructionSet::ldx_aby,
		NULL,
		InstructionSet::cpy_imm,
		InstructionSet::cmp_idx,
		NULL,
		NULL,
		InstructionSet::cpy_zpg,
		InstructionSet::cmp_zpg,
		InstructionSet::dec_zpg,
		NULL,
		InstructionSet::iny_imp,
		InstructionSet::cmp_imm,
		InstructionSet::dex_imp,
		NULL,
		InstructionSet::cpy_abs,
		InstructionSet::cmp_abs,
		InstructionSet::dec_abs,
		NULL,
		InstructionSet::bne_rel,
		InstructionSet::cmp_idy,
		NULL,
		NULL,
		NULL,
		InstructionSet::cmp_zpx,
		InstructionSet::dec_zpx,
		NULL,
		InstructionSet::cld_imp,
		InstructionSet::cmp_aby,
		NULL,
		NULL,
		NULL,
		InstructionSet::cmp_abx,
		InstructionSet::dec_abx,
		NULL,
		InstructionSet::cpx_imm,
		InstructionSet::sbc_idx,
		NULL,
		NULL,
		InstructionSet::cpx_zpg,
		InstructionSet::sbc_zpg,
		InstructionSet::inc_zpg,
		NULL,
		InstructionSet::inx_imp,
		InstructionSet::sbc_imm,
		InstructionSet::nop_imp,
		NULL,
		InstructionSet::cpx_abs,
		InstructionSet::sbc_abs,
		InstructionSet::inc_abs,
		NULL,
		InstructionSet::beq_rel,
		InstructionSet::sbc_idy,
		NULL,
		NULL,
		NULL,
		InstructionSet::sbc_zpx,
		InstructionSet::inc_zpx,
		NULL,
		InstructionSet::sed_imp,
		InstructionSet::sbc_aby,
		NULL,
		NULL,
		NULL,
		InstructionSet::sbc_abx,
		InstructionSet::inc_abx,
		NULL
	};

#define SET_ZN(x) set(cpu.P, FZERO, ((x) == 0)); set(cpu.P, FNEG, isset((x), 7));
#define PAGE_CROSSED(a, b) ((((uint16)a)/0x100) != (((uint16)b)/0x100))

	//brk, Implied
	int InstructionSet::brk_imp(CPU& cpu) {
		cpu.PC++; //brk treated as a 2 byte instruction, so PC is incremented by 2, but we've already incremented PC by getting the opcode
		cpu.push16(cpu.PC);
		cpu.push8(cpu.P);
		cpu.PC = cpu.m.getIRQ();
		set(cpu.P, FINT, 1);
		set(cpu.P, FBRK, 1);
		return 7;
	}

	//ora, (Indirect,X)
	int InstructionSet::ora_idx(CPU& cpu) {
		uint8 lo = cpu.fetch()+cpu.X; uint8 hi = lo+1; //Wraps around
		cpu.A |= cpu.m.r8(join(cpu.m.r8(lo), cpu.m.r8(hi)));
		SET_ZN(cpu.A);
		return 6;
	}

	//ora, Zero Page
	int InstructionSet::ora_zpg(CPU& cpu) {
		cpu.A |= cpu.m.r8(cpu.fetch());
		SET_ZN(cpu.A);
		return 3;
	}

	//asl, Zero Page
	int InstructionSet::asl_zpg(CPU& cpu) {
		uint8 addr = cpu.fetch();
		uint8 val = cpu.m.r8(addr);
		set(cpu.P, FCARRY, isset(val, 7));
		val <<= 1;
		cpu.m.w8(addr, val);
		SET_ZN(val);
		return 5;
	}

	//php, Implied
	int InstructionSet::php_imp(CPU& cpu) {
		cpu.push8(cpu.P);
		return 3;
	}

	//ora, Immediate
	int InstructionSet::ora_imm(CPU& cpu) {
		cpu.A |= cpu.fetch();
		SET_ZN(cpu.A);
		return 2;
	}

	//asl, Accumulator
	int InstructionSet::asl_imp(CPU& cpu) {
		set(cpu.P, FCARRY, isset(cpu.A, 7));
		cpu.A <<= 1;
		SET_ZN(cpu.A);
		return 2;
	}

	//ora, Absolute
	int InstructionSet::ora_abs(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		cpu.A |= cpu.m.r8(join(lo, hi));
		SET_ZN(cpu.A);
		return 4;
	}

	//asl, Absolute
	int InstructionSet::asl_abs(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		uint16 addr = join(lo, hi);
		uint8 val = cpu.m.r8(addr);
		set(cpu.P, FCARRY, isset(val, 7));
		val <<= 1;
		cpu.m.w8(addr, val);
		SET_ZN(val);
		return 6;
	}

	//bpl, Relative
	int InstructionSet::bpl_rel(CPU& cpu) {
		int8 rel = cpu.fetch();
		if (isset(cpu.P, FNEG)) return 2;
		bool page = PAGE_CROSSED(cpu.PC, int16(cpu.PC)+rel);
		cpu.PC = int16(cpu.PC)+rel;
		return 3+page;
	}

	//ora, (Indirect),Y
	int InstructionSet::ora_idy(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = lo+1;
		uint16 addr = join(cpu.m.r8(lo), cpu.m.r8(hi));

		bool page = PAGE_CROSSED(addr, addr+cpu.Y);
		cpu.A |= cpu.m.r8(addr+cpu.Y);
		SET_ZN(cpu.A);
		return 5+page;
	}

	//ora, Zero Page,X
	int InstructionSet::ora_zpx(CPU& cpu) {
		uint8 addr = cpu.fetch()+cpu.X;
		cpu.A |= cpu.m.r8(addr);
		SET_ZN(cpu.A);
		return 4;
	}

	//asl, Zero Page,X
	int InstructionSet::asl_zpx(CPU& cpu) {
		uint8 addr = cpu.fetch()+cpu.X;
		uint8 val = cpu.m.r8(addr);
		set(cpu.P, FCARRY, isset(val, 7));
		val <<= 1;
		cpu.m.w8(addr, val);
		SET_ZN(val);
		return 6;
	}

	//clc, Implied
	int InstructionSet::clc_imp(CPU& cpu) {
		set(cpu.P, FCARRY, 0);
		return 2;
	}

	//ora, Absolute,Y
	int InstructionSet::ora_aby(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		uint16 addr = join(lo, hi);

		bool page = PAGE_CROSSED(addr, addr+cpu.Y);
		cpu.A |= cpu.m.r8(addr+cpu.Y);
		SET_ZN(cpu.A);
		return 4+page;
	}

	//ora, Absolute,X
	int InstructionSet::ora_abx(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		uint16 addr = join(lo, hi);

		bool page = PAGE_CROSSED(addr, addr+cpu.X);
		cpu.A |= cpu.m.r8(addr+cpu.X);
		SET_ZN(cpu.A);
		return 4+page;
	}

	//asl, Absolute,X
	int InstructionSet::asl_abx(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		uint16 addr = join(lo, hi)+cpu.X;
		uint8 val = cpu.m.r8(addr);
		set(cpu.P, FCARRY, isset(val, 7));
		val <<= 1;
		cpu.m.w8(addr, val);
		SET_ZN(val);
		return 7;
	}

	//jsr, Absolute
	int InstructionSet::jsr_abs(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		uint16 addr = join(lo, hi);
		cpu.push16(cpu.PC-1); //Push PC - 1, due to 6502 stupidity :P
		return 6;
	}

	//and, (Indirect,X)
	int InstructionSet::and_idx(CPU& cpu) {
		uint8 lo = cpu.fetch()+cpu.X; uint8 hi = lo+1; //Wraps around
		cpu.A &= cpu.m.r8(join(cpu.m.r8(lo), cpu.m.r8(hi)));
		SET_ZN(cpu.A);
		return 6;
	}

	//bit, Zero Page
	int InstructionSet::bit_zpg(CPU& cpu) {
		uint8 val = cpu.m.r8(cpu.fetch());
		set(cpu.P, FOVER, isset(val, 6));
		set(cpu.P, FNEG, isset(val, 7));
		set(cpu.P, FZERO, (cpu.A&val));
		return 3;
	}

	//and, Zero Page
	int InstructionSet::and_zpg(CPU& cpu) {
		cpu.A &= cpu.m.r8(cpu.fetch());
		SET_ZN(cpu.A);
		return 3;
	}

	//rol, Zero Page
	int InstructionSet::rol_zpg(CPU& cpu) {
		uint8 addr = cpu.fetch();
		uint8 val = cpu.m.r8(addr);
		bool newcarry = isset(val, 7);
		val <<= 1;
		set(val, 0, isset(cpu.P, FCARRY));
		set(cpu.P, FCARRY, newcarry);
		cpu.m.w8(addr, val);
		SET_ZN(val);
		return 5;
	}

	//plp, Implied
	int InstructionSet::plp_imp(CPU& cpu) {
		cpu.P = cpu.pop8();
		return 4;
	}

	//and, Immediate
	int InstructionSet::and_imm(CPU& cpu) {
		cpu.A &= cpu.fetch();
		SET_ZN(cpu.A);
		return 2;
	}

	//rol, Accumulator
	int InstructionSet::rol_imp(CPU& cpu) {
		bool newcarry = isset(cpu.A, 7);
		cpu.A <<= 1;
		set(cpu.A, 0, isset(cpu.P, FCARRY));
		set(cpu.P, FCARRY, newcarry);
		SET_ZN(cpu.A);
		return 2;
	}

	//bit, Absolute
	int InstructionSet::bit_abs(CPU& cpu) {
		uint8 lo = cpu.fetch(); hi = cpu.fetch();
		uint8 val = cpu.m.r8(join(lo, hi));
		set(cpu.P, FOVER, isset(val, 6));
		set(cpu.P, FNEG, isset(val, 7));
		set(cpu.P, FZERO, (cpu.A&val));
		return 4;
	}

	//and, Absolute
	int InstructionSet::and_abs(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		cpu.A &= cpu.m.r8(join(lo, hi));
		SET_ZN(cpu.A);
		return 4;
	}

	//rol, Absolute
	int InstructionSet::rol_abs(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		uint16 addr = join(lo, hi);
		uint8 val = cpu.m.r8(addr);
		bool newcarry = isset(val, 7);
		val <<= 1;
		set(val, 0, isset(cpu.P, FCARRY));
		set(cpu.P, FCARRY, newcarry);
		cpu.m.w8(addr, val);
		SET_ZN(val);
		return 6;
	}

	//bmi, Relative
	int InstructionSet::bmi_rel(CPU& cpu) {
		int8 rel = cpu.fetch();
		if (!isset(cpu.P, FNEG)) return 2;
		bool page = PAGE_CROSSED(cpu.PC, int16(cpu.PC)+rel);
		cpu.PC = int16(cpu.PC)+rel;
		return 3+page;
	}

	//and, (Indirect),Y
	int InstructionSet::and_idy(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = lo+1; // Wraps
		uint8 addr = join(cpu.m.r8(lo), cpu.m.r8(hi));

		bool page = PAGE_CROSSED(addr, addr+cpu.Y);
		cpu.A &= cpu.m.r8(addr+cpu.Y);
		SET_ZN(cpu.A);
		return 5+page;
	}

	//and, Zero Page,X
	int InstructionSet::and_zpx(CPU& cpu) {
		uint8 addr = cpu.fetch()+cpu.X; //Wraps
		cpu.A &= cpu.m.r8(addr);
		SET_ZN(cpu.A);
		return 4;
	}

	//rol, Zero Page,X
	int InstructionSet::rol_zpx(CPU& cpu) {
		uint8 addr = cpu.fetch()+cpu.X; //Wraps
		uint8 val = cpu.m.r8(addr);
		bool newcarry = isset(val, 7);
		val <<= 1;
		set(val, 0, isset(cpu.P, FCARRY));
		set(cpu.P, FCARRY, newcarry);
		cpu.m.w8(addr, val);
		SET_ZN(val);
		return 6;
	}

	//sec, Implied
	int InstructionSet::sec_imp(CPU& cpu) {
		set(cpu.P, FCARRY, 1);
		return 2;
	}

	//and, Absolute,Y
	int InstructionSet::and_aby(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		uint16 addr = join(lo, hi);

		bool page = PAGE_CROSSED(addr, addr+cpu.Y);
		cpu.A &= cpu.m.r8(addr+cpu.Y);
		SET_ZN(cpu.A);
		return 4+page;
	}

	//and, Absolute,X
	int InstructionSet::and_abx(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		uint16 addr = join(lo, hi);

		bool page = PAGE_CROSSED(addr, addr+cpu.X);
		cpu.A &= cpu.m.r8(addr+cpu.X);
		SET_ZN(cpu.A);
		return 4+page;
	}

	//rol, Absolute,X
	int InstructionSet::rol_abx(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		uint16 addr = join(lo, hi)+cpu.X;
		uint8 val = cpu.m.r8(addr);
		bool newcarry = isset(val, 7);
		val <<= 1;
		set(val, 0, isset(cpu.P, FCARRY));
		set(cpu.P, FCARRY, newcarry);
		cpu.m.w8(addr, val);
		SET_ZN(val);
		return 7;
	}

	//rti, Implied
	int InstructionSet::rti_imp(CPU& cpu) {
		cpu.P = cpu.pop8();
		cpu.PC = cpu.pop16();
		return 6;
	}

	//eor, (Indirect,X)
	int InstructionSet::eor_idx(CPU& cpu) {
		uint8 lo = cpu.fetch()+cpu.X; uint8 hi = lo+1; //Wraps
		cpu.A |= cpu.m.r8(join(cpu.m.r8(lo), cpu.m.r8(hi)));
		SET_ZN(cpu.A);
		return 6;
	}

	//eor, Zero Page
	int InstructionSet::eor_zpg(CPU& cpu) {
		cpu.A |= cpu.m.r8(cpu.fetch());
		SET_ZN(cpu.A);
		return 3;
	}

	//lsr, Zero Page
	int InstructionSet::lsr_zpg(CPU& cpu) {
		uint8 addr = cpu.fetch();
		uint8 val = cpu.m.r8(addr);
		set(cpu.P, FCARRY, isset(val, 0));
		val >>= 1;
		cpu.m.w8(addr, val);
		SET_ZN(val);
		return 5;
	}

	//pha, Implied
	int InstructionSet::pha_imp(CPU& cpu) {
		cpu.push8(cpu.A);
		return 3;
	}

	//eor, Immediate
	int InstructionSet::eor_imm(CPU& cpu) {
		cpu.A |= cpu.fetch();
		SET_ZN(cpu.A);
		return 2;
	}

	//lsr, Accumulator
	int InstructionSet::lsr_imp(CPU& cpu) {
		set(cpu.P, FCARRY, isset(cpu.A, 0));
		cpu.A >>= 1;
		SET_ZN(cpu.A);
		return 2;
	}

	//jmp, Absolute
	int InstructionSet::jmp_abs(CPU& cpu) {
		uint8 lo = cpu.fetch(); hi = cpu.fetch();
		cpu.PC = join(lo, hi);
		return 3;
	}

	//eor, Absolute
	int InstructionSet::eor_abs(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		cpu.A |= cpu.m.r8(join(lo, hi));
		SET_ZN(cpu.A);
		return 4;
	}

	//lsr, Absolute
	int InstructionSet::lsr_abs(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		uint16 addr = join(lo, hi);
		uint8 val = cpu.m.r8(addr);
		set(cpu.P, FCARRY, isset(val, 0));
		val >>= 1;
		cpu.m.w8(addr, val);
		SET_ZN(val);
		return 6;
	}

	//bvc, Relative
	int InstructionSet::bvc_rel(CPU& cpu) {
		int8 rel = cpu.fetch();
		if (isset(cpu.P, FOVER)) return 2;
		bool page = PAGE_CROSSED(cpu.PC, int16(cpu.PC)+rel);
		cpu.PC = int16(cpu.PC)+rel;
		return 3+page;
	}

	//eor, (Indirect),Y
	int InstructionSet::eor_idy(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = lo+1;
		uint8 addr = join(cpu.m.r8(lo), cpu.m.r8(hi));

		bool page = PAGE_CROSSED(addr, addr+cpu.Y);
		cpu.A |= cpu.m.r8(addr+cpu.Y):
		SET_ZN(cpu.A);
		return 5+page;
	}

	//eor, Zero Page,X
	int InstructionSet::eor_zpx(CPU& cpu) {
		uint8 addr = cpu.fetch() + cpu.X; //Wraps
		cpu.A |= cpu.m.r8(addr);
		SET_ZN(cpu.A);
		return 4;
	}

	//lsr, Zero Page,X
	int InstructionSet::lsr_zpx(CPU& cpu) {
		uint8 addr = cpu.fetch() + cpu.X; //Wraps
		uint8 val = cpu.m.r8(addr);
		set(cpu.P, FCARRY, isset(val, 0));
		val >>= 1;
		cpu.m.w8(addr, val);
		SET_ZN(val);
		return 6;
	}

	//cli, Implied
	int InstructionSet::cli_imp(CPU& cpu) {
		set(cpu.P, FINT, 0);
	}

	//eor, Absolute,Y
	int InstructionSet::eor_aby(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		uint16 addr = join(lo, hi);

		bool page = PAGE_CROSSED(addr, addr+cpu.Y);
		cpu.A |= cpu.m.r8(addr+cpu.Y);
		SET_ZN(cpu.A);
		return 4+page;
	}

	//eor, Absolute,X
	int InstructionSet::eor_abx(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		uint16 addr = join(lo, hi);

		bool page = PAGE_CROSSED(addr, addr+cpu.X);
		cpu.A |= cpu.m.r8(addr+cpu.X);
		SET_ZN(cpu.A);
		return 4+page;
	}

	//lsr, Absolute,X
	int InstructionSet::lsr_abx(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		uint16 addr = join(lo, hi) + cpu.X;
		uint8 val = cpu.m.r8(addr);
		set(cpu.P, FCARRY, isset(val, 0));
		val >>= 1;
		cpu.m.w8(addr, val);
		SET_ZN(val);
		return 7;
	}

	//rts, Implied
	int InstructionSet::rts_imp(CPU& cpu) {
		cpu.PC = cpu.pop16()+1;
		return 6;
	}

	//adc, (Indirect,X)
	int InstructionSet::adc_idx(CPU& cpu) {
		uint8 lo = cpu.fetch()+cpu.X; uint8 hi = lo+1; //Wraps
		int8 val = cpu.m.r8(join(cpu.m.r8(lo), cpu.m.r8(hi)));
		int16 ans = int8(cpu.A) + val + isset(cpu.P, FCARRY);
		cpu.A = ans;
		SET_ZN(cpu.A);
		set(cpu.P, FCARRY, int16(cpu.A) != ans);
		set(cpu.P, FOVER, int16(cpu.A) != ans);
		return 6;
	}

	//adc, Zero Page
	int InstructionSet::adc_zpg(CPU& cpu) {
		int8 val = cpu.m.r8(cpu.fetch());
		int16 ans = int8(cpu.A) + val + isset(cpu.P, FCARRY);
		cpu.A = ans;
		SET_ZN(cpu.A);
		set(cpu.P, FCARRY, int16(cpu.A) != ans);
		set(cpu.P, FOVER, int16(cpu.A) != ans);
		return 3;
	}

	//ror, Zero Page
	int InstructionSet::ror_zpg(CPU& cpu) {
		uint8 val = cpu.m.r8(cpu.fetch());
		bool newcarry = isset(val, 0);
		val >>= 1;
		set(val, 7, isset(cpu.P, FCARRY));
		set(cpu.P, FCARRY, newcarry);
		cpu.m.w8(addr, val);
		SET_ZN(val);
		return 5;
	}

	//pla, Implied
	int InstructionSet::pla_imp(CPU& cpu) {
		cpu.A = cpu.pop8();
		SET_ZN(cpu.A);
		return 4;
	}

	//adc, Immediate
	int InstructionSet::adc_imm(CPU& cpu) {
		int8 val = cpu.fetch();
		int16 ans = int8(cpu.A) + val + isset(cpu.P, FCARRY);
		cpu.A = ans;
		SET_ZN(cpu.A);
		set(cpu.P, FCARRY, int16(cpu.A) != ans);
		set(cpu.P, FOVER, int16(cpu.A) != ans);
		return 2;
	}

	//ror, Accumulator
	int InstructionSet::ror_imp(CPU& cpu) {
		bool newcarry = isset(cpu.A, 0);
		cpu.A >>= 1;
		set(cpu.A, 7, isset(cpu.P, FCARRY));
		set(cpu.P, FCARRY, newcarry);
		SET_ZN(cpu.A);
		return 2;
	}

	//jmp, Indirect
	int InstructionSet::jmp_ind(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		setlo(cpu.PC, cpu.m.r8(join(lo, hi)));
		lo++; //Will wrap from 0xFF to 0x00 to account for nmos 6502 jmp indirect bug
		sethi(cpu.PC, cpu.m.r8(join(lo, hi)));
		return 5;
	}

	//adc, Absolute
	int InstructionSet::adc_abs(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch(); //Wraps
		int8 val = cpu.m.r8(join(lo, hi));
		int16 ans = int8(cpu.A) + val + isset(cpu.P, FCARRY);
		cpu.A = ans;
		SET_ZN(cpu.A);
		set(cpu.P, FCARRY, int16(cpu.A) != ans);
		set(cpu.P, FOVER, int16(cpu.A) != ans);
		return 4;
	}

	//ror, Absolute
	int InstructionSet::ror_abs(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		uint16 addr = join(lo, hi);
		uint8 val = cpu.m.r8(addr);
		bool newcarry = isset(val, 0);
		val >>= 1;
		set(val, 7, isset(cpu.P, FCARRY));
		set(cpu.P, FCARRY, newcarry);
		cpu.m.w8(addr, val);
		SET_ZN(val);
		return 6;
	}

	//bvs, Relative
	int InstructionSet::bvs_rel(CPU& cpu) {
		int8 rel = cpu.fetch();
		if (!isset(cpu.P, FOVER)) return 2;
		bool page = PAGE_CROSSED(cpu.PC, int16(cpu.PC)+rel);
		cpu.PC = int16(cpu.PC)+rel;
		return 3+page;
	}

	//adc, (Indirect),Y
	int InstructionSet::adc_idy(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = lo+1; //Wraps
		uint16 addr = join(cpu.m.r8(lo), cpu.m.r8(hi);
		bool page = PAGE_CROSSED(addr, addr+cpu.Y);

		int8 val = cpu.m.r8(addr+cpu.Y);
		int16 ans = int8(cpu.A) + val + isset(cpu.P, FCARRY);
		cpu.A = ans;
		SET_ZN(cpu.A);
		set(cpu.P, FCARRY, int16(cpu.A) != ans);
		set(cpu.P, FOVER, int16(cpu.A) != ans);
		return 5+page;
	}

	//adc, Zero Page,X
	int InstructionSet::adc_zpx(CPU& cpu) {
		uint8 addr = cpu.fetch()+cpu.X; //Wraps
		int8 val = cpu.m.r8(addr);
		int16 ans = int8(cpu.A) + val + isset(cpu.P, FCARRY);
		cpu.A = ans;
		SET_ZN(cpu.A);
		set(cpu.P, FCARRY, int16(cpu.A) != ans);
		set(cpu.P, FOVER, int16(cpu.A) != ans);
		return 4;
	}

	//ror, Zero Page,X
	int InstructionSet::ror_zpx(CPU& cpu) {
		uint16 addr = cpu.fetch() + cpu.X; //Wraps
		uint8 val = cpu.m.r8(addr);
		bool newcarry = isset(val, 0);
		val >>= 1;
		set(val, 7, isset(cpu.P, FCARRY));
		set(cpu.P, FCARRY, newcarry);
		cpu.m.w8(addr, val);
		SET_ZN(val);
		return 6;
	}

	//sei, Implied
	int InstructionSet::sei_imp(CPU& cpu) {
		set(cpu.P, FINT, 1);
		return 2;
	}

	//adc, Absolute,Y
	int InstructionSet::adc_aby(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch(); //Wraps
		uint16 addr = join(lo, hi);
		bool page = PAGE_CROSSED(addr, addr+cpu.Y);

		int8 val = cpu.m.r8(addr+cpu.Y);
		int16 ans = int8(cpu.A) + val + isset(cpu.P, FCARRY);
		cpu.A = ans;
		SET_ZN(cpu.A);
		set(cpu.P, FCARRY, int16(cpu.A) != ans);
		set(cpu.P, FOVER, int16(cpu.A) != ans);
		return 4+page;
	}

	//adc, Absolute,X
	int InstructionSet::adc_abx(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		uint16 addr = join(lo, hi);
		bool page = PAGE_CROSSED(addr, addr+cpu.X);

		int8 val = cpu.m.r8(addr+cpu.X);
		int16 ans = int8(cpu.A) + val + isset(cpu.P, FCARRY);
		cpu.A = ans;
		SET_ZN(cpu.A);
		set(cpu.P, FCARRY, int16(cpu.A) != ans);
		set(cpu.P, FOVER, int16(cpu.A) != ans);
		return 4+page;
	}

	//ror, Absolute,X
	int InstructionSet::ror_abx(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		uint16 addr = join(lo, hi) + cpu.X;
		uint8 val = cpu.m.r8(addr);
		bool newcarry = isset(val, 0);
		val >>= 1;
		set(val, 7, isset(cpu.P, FCARRY));
		set(cpu.P, FCARRY, newcarry);
		cpu.m.w8(addr, val);
		SET_ZN(val);
		return 7;
	}

	//sta, (Indirect,X)
	int InstructionSet::sta_idx(CPU& cpu) {
		uint8 lo = cpu.fetch()+cpu.X; uint8 hi = lo+1;
		cpu.m.w8(join(cpu.m.r8(lo), cpu.m.r8(hi)), cpu.A);
		return 6;
	}

	//sty, Zero Page
	int InstructionSet::sty_zpg(CPU& cpu) {
		cpu.m.w8(cpu.fetch(), cpu.Y);
		return 3;
	}

	//sta, Zero Page
	int InstructionSet::sta_zpg(CPU& cpu) {
		cpu.m.w8(cpu.fetch(), cpu.A);
		return 3;
	}

	//stx, Zero Page
	int InstructionSet::stx_zpg(CPU& cpu) {
		cpu.m.w8(cpu.fetch(), cpu.X);
		return 3;
	}

	//dey, Implied
	int InstructionSet::dey_imp(CPU& cpu) {
		cpu.Y--;
		SET_ZN(cpu.Y);
		return 2;
	}

	//txa, Implied
	int InstructionSet::txa_imp(CPU& cpu) {
		cpu.A = cpu.X;
		SET_ZN(cpu.A);
		return 2;
	}

	//sty, Absolute
	int InstructionSet::sty_abs(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		cpu.m.w8(join(lo, hi), cpu.Y);
		return 4;
	}

	//sta, Absolute
	int InstructionSet::sta_abs(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		cpu.m.w8(join(lo, hi), cpu.A);
		return 4;
	}

	//stx, Absolute
	int InstructionSet::stx_abs(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		cpu.m.w8(join(lo, hi), cpu.X);
		return 4;
	}

	//bcc, Relative
	int InstructionSet::bcc_rel(CPU& cpu) {
		int8 rel = cpu.fetch();
		if (isset(cpu.P, FCARRY)) return 2;
		bool page = PAGE_CROSSED(cpu.PC, int16(cpu.PC)+rel);
		cpu.PC = int16(cpu.PC)+rel;
		return 3+page;
	}

	//sta, (Indirect),Y
	int InstructionSet::sta_idy(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = lo+1;
		cpu.m.w8(join(cpu.m.r8(lo), cpu.m.r8(hi))+cpu.Y, cpu.A);
		return 6;
	}

	//sty, Zero Page,X
	int InstructionSet::sty_zpx(CPU& cpu) {
		cpu.m.w8(cpu.fetch()+cpu.X, cpu.Y);
		return 4;
	}

	//sta, Zero Page,X
	int InstructionSet::sta_zpx(CPU& cpu) {
		cpu.m.w8(cpu.fetch()+cpu.X, cpu.A);
		return 4;
	}

	//stx, Zero Page,Y
	int InstructionSet::stx_zpy(CPU& cpu) {
		cpu.m.w8(cpu.fetch()+cpu.Y, cpu.X);
		return 4;
	}

	//tya, Implied
	int InstructionSet::tya_imp(CPU& cpu) {
		cpu.A = cpu.Y;
		SET_ZN(cpu.A);
		return 2;
	}

	//sta, Absolute,Y
	int InstructionSet::sta_aby(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		cpu.m.w8(join(lo, hi)+cpu.Y, cpu.A);
		return 5;
	}

	//txs, Implied
	int InstructionSet::txs_imp(CPU& cpu) {
		cpu.SP = X;
		return 2;
	}

	//sta, Absolute,X
	int InstructionSet::sta_abx(CPU& cpu) {
		uint8 lo = cpu.fetch(); uint8 hi = cpu.fetch();
		cpu.m.w8(join(lo, hi)+cpu.X, cpu.A);
		return 5;
	}

	//ldy, Immediate
	int InstructionSet::ldy_imm(CPU& cpu) {
	}

	//lda, (Indirect,X)
	int InstructionSet::lda_idx(CPU& cpu) {
	}

	//ldx, Immediate
	int InstructionSet::ldx_imm(CPU& cpu) {
	}

	//ldy, Zero Page
	int InstructionSet::ldy_zpg(CPU& cpu) {
	}

	//lda, Zero Page
	int InstructionSet::lda_zpg(CPU& cpu) {
	}

	//ldx, Zero Page
	int InstructionSet::ldx_zpg(CPU& cpu) {
	}

	//tay, Implied
	int InstructionSet::tay_imp(CPU& cpu) {
	}

	//lda, Immediate
	int InstructionSet::lda_imm(CPU& cpu) {
	}

	//tax, Implied
	int InstructionSet::tax_imp(CPU& cpu) {
	}

	//ldy, Absolute
	int InstructionSet::ldy_abs(CPU& cpu) {
	}

	//lda, Absolute
	int InstructionSet::lda_abs(CPU& cpu) {
	}

	//ldx, Absolute
	int InstructionSet::ldx_abs(CPU& cpu) {
	}

	//bcs, Relative
	int InstructionSet::bcs_rel(CPU& cpu) {
	}

	//lda, (Indirect),Y
	int InstructionSet::lda_idy(CPU& cpu) {
	}

	//ldy, Zero Page,X
	int InstructionSet::ldy_zpx(CPU& cpu) {
	}

	//lda, Zero Page,X
	int InstructionSet::lda_zpx(CPU& cpu) {
	}

	//ldx, Zero Page,Y
	int InstructionSet::ldx_zpy(CPU& cpu) {
	}

	//clv, Implied
	int InstructionSet::clv_imp(CPU& cpu) {
	}

	//lda, Absolute,Y
	int InstructionSet::lda_aby(CPU& cpu) {
	}

	//tsx, Implied
	int InstructionSet::tsx_imp(CPU& cpu) {
	}

	//ldy, Absolute,X
	int InstructionSet::ldy_abx(CPU& cpu) {
	}

	//lda, Absolute,X
	int InstructionSet::lda_abx(CPU& cpu) {
	}

	//ldx, Absolute,Y
	int InstructionSet::ldx_aby(CPU& cpu) {
	}

	//cpy, Immediate
	int InstructionSet::cpy_imm(CPU& cpu) {
	}

	//cmp, (Indirect,X)
	int InstructionSet::cmp_idx(CPU& cpu) {
	}

	//cpy, Zero Page
	int InstructionSet::cpy_zpg(CPU& cpu) {
	}

	//cmp, Zero Page
	int InstructionSet::cmp_zpg(CPU& cpu) {
	}

	//dec, Zero Page
	int InstructionSet::dec_zpg(CPU& cpu) {
	}

	//iny, Implied
	int InstructionSet::iny_imp(CPU& cpu) {
	}

	//cmp, Immediate
	int InstructionSet::cmp_imm(CPU& cpu) {
	}

	//dex, Implied
	int InstructionSet::dex_imp(CPU& cpu) {
	}

	//cpy, Absolute
	int InstructionSet::cpy_abs(CPU& cpu) {
	}

	//cmp, Absolute
	int InstructionSet::cmp_abs(CPU& cpu) {
	}

	//dec, Absolute
	int InstructionSet::dec_abs(CPU& cpu) {
	}

	//bne, Relative
	int InstructionSet::bne_rel(CPU& cpu) {
	}

	//cmp, (Indirect),Y
	int InstructionSet::cmp_idy(CPU& cpu) {
	}

	//cmp, Zero Page,X
	int InstructionSet::cmp_zpx(CPU& cpu) {
	}

	//dec, Zero Page,X
	int InstructionSet::dec_zpx(CPU& cpu) {
	}

	//cld, Implied
	int InstructionSet::cld_imp(CPU& cpu) {
	}

	//cmp, Absolute,Y
	int InstructionSet::cmp_aby(CPU& cpu) {
	}

	//cmp, Absolute,X
	int InstructionSet::cmp_abx(CPU& cpu) {
	}

	//dec, Absolute,X
	int InstructionSet::dec_abx(CPU& cpu) {
	}

	//cpx, Immediate
	int InstructionSet::cpx_imm(CPU& cpu) {
	}

	//sbc, (Indirect,X)
	int InstructionSet::sbc_idx(CPU& cpu) {
	}

	//cpx, Zero Page
	int InstructionSet::cpx_zpg(CPU& cpu) {
	}

	//sbc, Zero Page
	int InstructionSet::sbc_zpg(CPU& cpu) {
	}

	//inc, Zero Page
	int InstructionSet::inc_zpg(CPU& cpu) {
	}

	//inx, Implied
	int InstructionSet::inx_imp(CPU& cpu) {
	}

	//sbc, Immediate
	int InstructionSet::sbc_imm(CPU& cpu) {
	}

	//nop, Implied
	int InstructionSet::nop_imp(CPU& cpu) {
	}

	//cpx, Absolute
	int InstructionSet::cpx_abs(CPU& cpu) {
	}

	//sbc, Absolute
	int InstructionSet::sbc_abs(CPU& cpu) {
	}

	//inc, Absolute
	int InstructionSet::inc_abs(CPU& cpu) {
	}

	//beq, Relative
	int InstructionSet::beq_rel(CPU& cpu) {
	}

	//sbc, (Indirect),Y
	int InstructionSet::sbc_idy(CPU& cpu) {
	}

	//sbc, Zero Page,X
	int InstructionSet::sbc_zpx(CPU& cpu) {
	}

	//inc, Zero Page,X
	int InstructionSet::inc_zpx(CPU& cpu) {
	}

	//sed, Implied
	int InstructionSet::sed_imp(CPU& cpu) {
	}

	//sbc, Absolute,Y
	int InstructionSet::sbc_aby(CPU& cpu) {
	}

	//sbc, Absolute,X
	int InstructionSet::sbc_abx(CPU& cpu) {
	}

	//inc, Absolute,X
	int InstructionSet::inc_abx(CPU& cpu) {
	}

}
