#ifndef NMOS6502_INSTRUCTIONS_HPP_
#define NMOS6502_INSTRUCTIONS_HPP_
#include "nmos6502/common.hpp"
#include "nmos6502/cpu.hpp"

namespace nmos6502 {

	typedef int (*Instruction)(CPU&);
	extern Instruction opcodes[]; ///< 256 possible opcodes, 151 of them are implemented

	class InstructionSet {
	public:
		//brk, Implied
		static int brk_imp(CPU& cpu);

		//ora, (Indirect,X)
		static int ora_idx(CPU& cpu);

		//ora, Zero Page
		static int ora_zpg(CPU& cpu);

		//asl, Zero Page
		static int asl_zpg(CPU& cpu);

		//php, Implied
		static int php_imp(CPU& cpu);

		//ora, Immediate
		static int ora_imm(CPU& cpu);

		//asl, Accumulator
		static int asl_imp(CPU& cpu);

		//ora, Absolute
		static int ora_abs(CPU& cpu);

		//asl, Absolute
		static int asl_abs(CPU& cpu);

		//bpl, Relative
		static int bpl_rel(CPU& cpu);

		//ora, (Indirect),Y
		static int ora_idy(CPU& cpu);

		//ora, Zero Page,X
		static int ora_zpx(CPU& cpu);

		//asl, Zero Page,X
		static int asl_zpx(CPU& cpu);

		//clc, Implied
		static int clc_imp(CPU& cpu);

		//ora, Absolute,Y
		static int ora_aby(CPU& cpu);

		//ora, Absolute,X
		static int ora_abx(CPU& cpu);

		//asl, Absolute,X
		static int asl_abx(CPU& cpu);

		//jsr, Absolute
		static int jsr_abs(CPU& cpu);

		//and, (Indirect,X)
		static int and_idx(CPU& cpu);

		//bit, Zero Page
		static int bit_zpg(CPU& cpu);

		//and, Zero Page
		static int and_zpg(CPU& cpu);

		//rol, Zero Page
		static int rol_zpg(CPU& cpu);

		//plp, Implied
		static int plp_imp(CPU& cpu);

		//and, Immediate
		static int and_imm(CPU& cpu);

		//rol, Accumulator
		static int rol_imp(CPU& cpu);

		//bit, Absolute
		static int bit_abs(CPU& cpu);

		//and, Absolute
		static int and_abs(CPU& cpu);

		//rol, Absolute
		static int rol_abs(CPU& cpu);

		//bmi, Relative
		static int bmi_rel(CPU& cpu);

		//and, (Indirect),Y
		static int and_idy(CPU& cpu);

		//and, Zero Page,X
		static int and_zpx(CPU& cpu);

		//rol, Zero Page,X
		static int rol_zpx(CPU& cpu);

		//sec, Implied
		static int sec_imp(CPU& cpu);

		//and, Absolute,Y
		static int and_aby(CPU& cpu);

		//and, Absolute,X
		static int and_abx(CPU& cpu);

		//rol, Absolute,X
		static int rol_abx(CPU& cpu);

		//rti, Implied
		static int rti_imp(CPU& cpu);

		//eor, (Indirect,X)
		static int eor_idx(CPU& cpu);

		//eor, Zero Page
		static int eor_zpg(CPU& cpu);

		//lsr, Zero Page
		static int lsr_zpg(CPU& cpu);

		//pha, Implied
		static int pha_imp(CPU& cpu);

		//eor, Immediate
		static int eor_imm(CPU& cpu);

		//lsr, Accumulator
		static int lsr_imp(CPU& cpu);

		//jmp, Absolute
		static int jmp_abs(CPU& cpu);

		//eor, Absolute
		static int eor_abs(CPU& cpu);

		//lsr, Absolute
		static int lsr_abs(CPU& cpu);

		//bvc, Relative
		static int bvc_rel(CPU& cpu);

		//eor, (Indirect),Y
		static int eor_idy(CPU& cpu);

		//eor, Zero Page,X
		static int eor_zpx(CPU& cpu);

		//lsr, Zero Page,X
		static int lsr_zpx(CPU& cpu);

		//cli, Implied
		static int cli_imp(CPU& cpu);

		//eor, Absolute,Y
		static int eor_aby(CPU& cpu);

		//eor, Absolute,X
		static int eor_abx(CPU& cpu);

		//lsr, Absolute,X
		static int lsr_abx(CPU& cpu);

		//rts, Implied
		static int rts_imp(CPU& cpu);

		//adc, (Indirect,X)
		static int adc_idx(CPU& cpu);

		//adc, Zero Page
		static int adc_zpg(CPU& cpu);

		//ror, Zero Page
		static int ror_zpg(CPU& cpu);

		//pla, Implied
		static int pla_imp(CPU& cpu);

		//adc, Immediate
		static int adc_imm(CPU& cpu);

		//ror, Accumulator
		static int ror_imp(CPU& cpu);

		//jmp, Indirect
		static int jmp_ind(CPU& cpu);

		//adc, Absolute
		static int adc_abs(CPU& cpu);

		//ror, Absolute
		static int ror_abs(CPU& cpu);

		//bvs, Relative
		static int bvs_rel(CPU& cpu);

		//adc, (Indirect),Y
		static int adc_idy(CPU& cpu);

		//adc, Zero Page,X
		static int adc_zpx(CPU& cpu);

		//ror, Zero Page,X
		static int ror_zpx(CPU& cpu);

		//sei, Implied
		static int sei_imp(CPU& cpu);

		//adc, Absolute,Y
		static int adc_aby(CPU& cpu);

		//adc, Absolute,X
		static int adc_abx(CPU& cpu);

		//ror, Absolute,X
		static int ror_abx(CPU& cpu);

		//sta, (Indirect,X)
		static int sta_idx(CPU& cpu);

		//sty, Zero Page
		static int sty_zpg(CPU& cpu);

		//sta, Zero Page
		static int sta_zpg(CPU& cpu);

		//stx, Zero Page
		static int stx_zpg(CPU& cpu);

		//dey, Implied
		static int dey_imp(CPU& cpu);

		//txa, Implied
		static int txa_imp(CPU& cpu);

		//sty, Absolute
		static int sty_abs(CPU& cpu);

		//sta, Absolute
		static int sta_abs(CPU& cpu);

		//stx, Absolute
		static int stx_abs(CPU& cpu);

		//bcc, Relative
		static int bcc_rel(CPU& cpu);

		//sta, (Indirect),Y
		static int sta_idy(CPU& cpu);

		//sty, Zero Page,X
		static int sty_zpx(CPU& cpu);

		//sta, Zero Page,X
		static int sta_zpx(CPU& cpu);

		//stx, Zero Page,Y
		static int stx_zpy(CPU& cpu);

		//tya, Implied
		static int tya_imp(CPU& cpu);

		//sta, Absolute,Y
		static int sta_aby(CPU& cpu);

		//txs, Implied
		static int txs_imp(CPU& cpu);

		//sta, Absolute,X
		static int sta_abx(CPU& cpu);

		//ldy, Immediate
		static int ldy_imm(CPU& cpu);

		//lda, (Indirect,X)
		static int lda_idx(CPU& cpu);

		//ldx, Immediate
		static int ldx_imm(CPU& cpu);

		//ldy, Zero Page
		static int ldy_zpg(CPU& cpu);

		//lda, Zero Page
		static int lda_zpg(CPU& cpu);

		//ldx, Zero Page
		static int ldx_zpg(CPU& cpu);

		//tay, Implied
		static int tay_imp(CPU& cpu);

		//lda, Immediate
		static int lda_imm(CPU& cpu);

		//tax, Implied
		static int tax_imp(CPU& cpu);

		//ldy, Absolute
		static int ldy_abs(CPU& cpu);

		//lda, Absolute
		static int lda_abs(CPU& cpu);

		//ldx, Absolute
		static int ldx_abs(CPU& cpu);

		//bcs, Relative
		static int bcs_rel(CPU& cpu);

		//lda, (Indirect),Y
		static int lda_idy(CPU& cpu);

		//ldy, Zero Page,X
		static int ldy_zpx(CPU& cpu);

		//lda, Zero Page,X
		static int lda_zpx(CPU& cpu);

		//ldx, Zero Page,Y
		static int ldx_zpy(CPU& cpu);

		//clv, Implied
		static int clv_imp(CPU& cpu);

		//lda, Absolute,Y
		static int lda_aby(CPU& cpu);

		//tsx, Implied
		static int tsx_imp(CPU& cpu);

		//ldy, Absolute,X
		static int ldy_abx(CPU& cpu);

		//lda, Absolute,X
		static int lda_abx(CPU& cpu);

		//ldx, Absolute,Y
		static int ldx_aby(CPU& cpu);

		//cpy, Immediate
		static int cpy_imm(CPU& cpu);

		//cmp, (Indirect,X)
		static int cmp_idx(CPU& cpu);

		//cpy, Zero Page
		static int cpy_zpg(CPU& cpu);

		//cmp, Zero Page
		static int cmp_zpg(CPU& cpu);

		//dec, Zero Page
		static int dec_zpg(CPU& cpu);

		//iny, Implied
		static int iny_imp(CPU& cpu);

		//cmp, Immediate
		static int cmp_imm(CPU& cpu);

		//dex, Implied
		static int dex_imp(CPU& cpu);

		//cpy, Absolute
		static int cpy_abs(CPU& cpu);

		//cmp, Absolute
		static int cmp_abs(CPU& cpu);

		//dec, Absolute
		static int dec_abs(CPU& cpu);

		//bne, Relative
		static int bne_rel(CPU& cpu);

		//cmp, (Indirect),Y
		static int cmp_idy(CPU& cpu);

		//cmp, Zero Page,X
		static int cmp_zpx(CPU& cpu);

		//dec, Zero Page,X
		static int dec_zpx(CPU& cpu);

		//cld, Implied
		static int cld_imp(CPU& cpu);

		//cmp, Absolute,Y
		static int cmp_aby(CPU& cpu);

		//cmp, Absolute,X
		static int cmp_abx(CPU& cpu);

		//dec, Absolute,X
		static int dec_abx(CPU& cpu);

		//cpx, Immediate
		static int cpx_imm(CPU& cpu);

		//sbc, (Indirect,X)
		static int sbc_idx(CPU& cpu);

		//cpx, Zero Page
		static int cpx_zpg(CPU& cpu);

		//sbc, Zero Page
		static int sbc_zpg(CPU& cpu);

		//inc, Zero Page
		static int inc_zpg(CPU& cpu);

		//inx, Implied
		static int inx_imp(CPU& cpu);

		//sbc, Immediate
		static int sbc_imm(CPU& cpu);

		//nop, Implied
		static int nop_imp(CPU& cpu);

		//cpx, Absolute
		static int cpx_abs(CPU& cpu);

		//sbc, Absolute
		static int sbc_abs(CPU& cpu);

		//inc, Absolute
		static int inc_abs(CPU& cpu);

		//beq, Relative
		static int beq_rel(CPU& cpu);

		//sbc, (Indirect),Y
		static int sbc_idy(CPU& cpu);

		//sbc, Zero Page,X
		static int sbc_zpx(CPU& cpu);

		//inc, Zero Page,X
		static int inc_zpx(CPU& cpu);

		//sed, Implied
		static int sed_imp(CPU& cpu);

		//sbc, Absolute,Y
		static int sbc_aby(CPU& cpu);

		//sbc, Absolute,X
		static int sbc_abx(CPU& cpu);

		//inc, Absolute,X
		static int inc_abx(CPU& cpu);
	};

}

#endif
