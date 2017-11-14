/* $Id$
 * (L)
*/

#include <otclasml/mnemtst.hxx>
#include <otclasml/StringView.hxx>
#include <otclasml/inttypes.hxx>
#include <otclasml/ConstStringMap.hxx>

namespace otclasml { namespace mnem {

static ConstStringMap::String mnem_strings[NENTRIES + 1] = {
	{ "abs", 3 }, // 0: ABS
	{ "abs.b", 5 }, // 1: ABS_B
	{ "abs.h", 5 }, // 2: ABS_H
	{ "absdif", 6 }, // 3: ABSDIF
	{ "absdif.b", 8 }, // 4: ABSDIF_B
	{ "absdif.h", 8 }, // 5: ABSDIF_H
	{ "absdifs", 7 }, // 6: ABSDIFS
	{ "absdifs.h", 9 }, // 7: ABSDIFS_H
	{ "abss", 4 }, // 8: ABSS
	{ "abss.h", 6 }, // 9: ABSS_H
	{ "add", 3 }, // 10: ADD
	{ "add.a", 5 }, // 11: ADD_A
	{ "add.b", 5 }, // 12: ADD_B
	{ "add.h", 5 }, // 13: ADD_H
	{ "addc", 4 }, // 14: ADDC
	{ "addi", 4 }, // 15: ADDI
	{ "addih", 5 }, // 16: ADDIH
	{ "addih.a", 7 }, // 17: ADDIH_A
	{ "adds", 4 }, // 18: ADDS
	{ "adds.h", 6 }, // 19: ADDS_H
	{ "adds.hu", 7 }, // 20: ADDS_HU
	{ "adds.u", 6 }, // 21: ADDS_U
	{ "addsc.a", 7 }, // 22: ADDSC_A
	{ "addsc.at", 8 }, // 23: ADDSC_AT
	{ "addx", 4 }, // 24: ADDX
	{ "and", 3 }, // 25: AND
	{ "and.and.t", 9 }, // 26: AND_AND_T
	{ "and.andn.t", 10 }, // 27: AND_ANDN_T
	{ "and.eq", 6 }, // 28: AND_EQ
	{ "and.ge", 6 }, // 29: AND_GE
	{ "and.ge.u", 8 }, // 30: AND_GE_U
	{ "and.lt", 6 }, // 31: AND_LT
	{ "and.lt.u", 8 }, // 32: AND_LT_U
	{ "and.ne", 6 }, // 33: AND_NE
	{ "and.nor.t", 9 }, // 34: AND_NOR_T
	{ "and.or.t", 8 }, // 35: AND_OR_T
	{ "and.t", 5 }, // 36: AND_T
	{ "andn", 4 }, // 37: ANDN
	{ "andn.t", 6 }, // 38: ANDN_T
	{ "bisr", 4 }, // 39: BISR
	{ "bmerge", 6 }, // 40: BMERGE
	{ "bsplit", 6 }, // 41: BSPLIT
	{ "cachea.i", 8 }, // 42: CACHEA_I
	{ "cachea.w", 8 }, // 43: CACHEA_W
	{ "cachea.wi", 9 }, // 44: CACHEA_WI
	{ "cachei.i", 8 }, // 45: CACHEI_I
	{ "cachei.w", 8 }, // 46: CACHEI_W
	{ "cachei.wi", 9 }, // 47: CACHEI_WI
	{ "cadd", 4 }, // 48: CADD
	{ "caddn", 5 }, // 49: CADDN
	{ "call", 4 }, // 50: CALL
	{ "calla", 5 }, // 51: CALLA
	{ "calli", 5 }, // 52: CALLI
	{ "clo", 3 }, // 53: CLO
	{ "clo.h", 5 }, // 54: CLO_H
	{ "cls", 3 }, // 55: CLS
	{ "cls.h", 5 }, // 56: CLS_H
	{ "clz", 3 }, // 57: CLZ
	{ "clz.h", 5 }, // 58: CLZ_H
	{ "cmov", 4 }, // 59: CMOV
	{ "cmovn", 5 }, // 60: CMOVN
	{ "cmpswap.w", 9 }, // 61: CMPSWAP_W
	{ "crc32", 5 }, // 62: CRC32
	{ "csub", 4 }, // 63: CSUB
	{ "csubn", 5 }, // 64: CSUBN
	{ "debug", 5 }, // 65: DEBUG
	{ "dextr", 5 }, // 66: DEXTR
	{ "disable", 7 }, // 67: DISABLE
	{ "div", 3 }, // 68: DIV
	{ "div.u", 5 }, // 69: DIV_U
	{ "dsync", 5 }, // 70: DSYNC
	{ "dvadj", 5 }, // 71: DVADJ
	{ "dvinit", 6 }, // 72: DVINIT
	{ "dvinit.b", 8 }, // 73: DVINIT_B
	{ "dvinit.bu", 9 }, // 74: DVINIT_BU
	{ "dvinit.h", 8 }, // 75: DVINIT_H
	{ "dvinit.hu", 9 }, // 76: DVINIT_HU
	{ "dvinit.u", 8 }, // 77: DVINIT_U
	{ "dvstep", 6 }, // 78: DVSTEP
	{ "dvstep.u", 8 }, // 79: DVSTEP_U
	{ "enable", 6 }, // 80: ENABLE
	{ "eq", 2 }, // 81: EQ
	{ "eq.a", 4 }, // 82: EQ_A
	{ "eq.b", 4 }, // 83: EQ_B
	{ "eq.h", 4 }, // 84: EQ_H
	{ "eq.w", 4 }, // 85: EQ_W
	{ "eqany.b", 7 }, // 86: EQANY_B
	{ "eqany.h", 7 }, // 87: EQANY_H
	{ "eqz.a", 5 }, // 88: EQZ_A
	{ "extr", 4 }, // 89: EXTR
	{ "extr.u", 6 }, // 90: EXTR_U
	{ "f_add.f", 7 }, // 91: F_ADD_F
	{ "f_cmp.f", 7 }, // 92: F_CMP_F
	{ "f_div.f", 7 }, // 93: F_DIV_F
	{ "f_itof", 6 }, // 94: F_ITOF
	{ "f_madd.f", 8 }, // 95: F_MADD_F
	{ "f_msub.f", 8 }, // 96: F_MSUB_F
	{ "f_mul.f", 7 }, // 97: F_MUL_F
	{ "f_q31tof", 8 }, // 98: F_Q31TOF
	{ "f_qseed.f", 9 }, // 99: F_QSEED_F
	{ "f_sub.f", 7 }, // 100: F_SUB_F
	{ "f_updfl", 7 }, // 101: F_UPDFL
	{ "f_utof", 6 }, // 102: F_UTOF
	{ "fcall", 5 }, // 103: FCALL
	{ "fcalla", 6 }, // 104: FCALLA
	{ "fcalli", 6 }, // 105: FCALLI
	{ "fret", 4 }, // 106: FRET
	{ "ftoi", 4 }, // 107: FTOI
	{ "ftoiz", 5 }, // 108: FTOIZ
	{ "ftoq31", 6 }, // 109: FTOQ31
	{ "ftoq31z", 7 }, // 110: FTOQ31Z
	{ "ftou", 4 }, // 111: FTOU
	{ "ftouz", 5 }, // 112: FTOUZ
	{ "ge", 2 }, // 113: GE
	{ "ge.a", 4 }, // 114: GE_A
	{ "ge.u", 4 }, // 115: GE_U
	{ "imask", 5 }, // 116: IMASK
	{ "ins.t", 5 }, // 117: INS_T
	{ "insert", 6 }, // 118: INSERT
	{ "insn.t", 6 }, // 119: INSN_T
	{ "isync", 5 }, // 120: ISYNC
	{ "ixmax", 5 }, // 121: IXMAX
	{ "ixmax.u", 7 }, // 122: IXMAX_U
	{ "ixmin", 5 }, // 123: IXMIN
	{ "ixmin.u", 7 }, // 124: IXMIN_U
	{ "j", 1 }, // 125: J
	{ "ja", 2 }, // 126: JA
	{ "jeq", 3 }, // 127: JEQ
	{ "jeq.a", 5 }, // 128: JEQ_A
	{ "jge", 3 }, // 129: JGE
	{ "jge.u", 5 }, // 130: JGE_U
	{ "jgez", 4 }, // 131: JGEZ
	{ "jgtz", 4 }, // 132: JGTZ
	{ "ji", 2 }, // 133: JI
	{ "jl", 2 }, // 134: JL
	{ "jla", 3 }, // 135: JLA
	{ "jlez", 4 }, // 136: JLEZ
	{ "jli", 3 }, // 137: JLI
	{ "jlt", 3 }, // 138: JLT
	{ "jlt.u", 5 }, // 139: JLT_U
	{ "jltz", 4 }, // 140: JLTZ
	{ "jne", 3 }, // 141: JNE
	{ "jne.a", 5 }, // 142: JNE_A
	{ "jned", 4 }, // 143: JNED
	{ "jnei", 4 }, // 144: JNEI
	{ "jnz", 3 }, // 145: JNZ
	{ "jnz.a", 5 }, // 146: JNZ_A
	{ "jnz.t", 5 }, // 147: JNZ_T
	{ "jz", 2 }, // 148: JZ
	{ "jz.a", 4 }, // 149: JZ_A
	{ "jz.t", 4 }, // 150: JZ_T
	{ "ld.a", 4 }, // 151: LD_A
	{ "ld.b", 4 }, // 152: LD_B
	{ "ld.bu", 5 }, // 153: LD_BU
	{ "ld.d", 4 }, // 154: LD_D
	{ "ld.da", 5 }, // 155: LD_DA
	{ "ld.h", 4 }, // 156: LD_H
	{ "ld.hu", 5 }, // 157: LD_HU
	{ "ld.q", 4 }, // 158: LD_Q
	{ "ld.w", 4 }, // 159: LD_W
	{ "ldlcx", 5 }, // 160: LDLCX
	{ "ldmst", 5 }, // 161: LDMST
	{ "lducx", 5 }, // 162: LDUCX
	{ "lea", 3 }, // 163: LEA
	{ "loop", 4 }, // 164: LOOP
	{ "loopu", 5 }, // 165: LOOPU
	{ "lt", 2 }, // 166: LT
	{ "lt.a", 4 }, // 167: LT_A
	{ "lt.b", 4 }, // 168: LT_B
	{ "lt.bu", 5 }, // 169: LT_BU
	{ "lt.h", 4 }, // 170: LT_H
	{ "lt.hu", 5 }, // 171: LT_HU
	{ "lt.u", 4 }, // 172: LT_U
	{ "lt.w", 4 }, // 173: LT_W
	{ "lt.wu", 5 }, // 174: LT_WU
	{ "madd", 4 }, // 175: MADD
	{ "madd.h", 6 }, // 176: MADD_H
	{ "madd.q", 6 }, // 177: MADD_Q
	{ "madd.u", 6 }, // 178: MADD_U
	{ "maddm.h", 7 }, // 179: MADDM_H
	{ "maddms.h", 8 }, // 180: MADDMS_H
	{ "maddr.h", 7 }, // 181: MADDR_H
	{ "maddr.q", 7 }, // 182: MADDR_Q
	{ "maddrs.h", 8 }, // 183: MADDRS_H
	{ "maddrs.q", 8 }, // 184: MADDRS_Q
	{ "madds", 5 }, // 185: MADDS
	{ "madds.h", 7 }, // 186: MADDS_H
	{ "madds.q", 7 }, // 187: MADDS_Q
	{ "madds.u", 7 }, // 188: MADDS_U
	{ "maddsu.h", 8 }, // 189: MADDSU_H
	{ "maddsum.h", 9 }, // 190: MADDSUM_H
	{ "maddsums.h", 10 }, // 191: MADDSUMS_H
	{ "maddsur.h", 9 }, // 192: MADDSUR_H
	{ "maddsurs.h", 10 }, // 193: MADDSURS_H
	{ "maddsus.h", 9 }, // 194: MADDSUS_H
	{ "max", 3 }, // 195: MAX
	{ "max.b", 5 }, // 196: MAX_B
	{ "max.bu", 6 }, // 197: MAX_BU
	{ "max.h", 5 }, // 198: MAX_H
	{ "max.hu", 6 }, // 199: MAX_HU
	{ "max.u", 5 }, // 200: MAX_U
	{ "mfcr", 4 }, // 201: MFCR
	{ "min", 3 }, // 202: MIN
	{ "min.b", 5 }, // 203: MIN_B
	{ "min.bu", 6 }, // 204: MIN_BU
	{ "min.h", 5 }, // 205: MIN_H
	{ "min.hu", 6 }, // 206: MIN_HU
	{ "min.u", 5 }, // 207: MIN_U
	{ "mov", 3 }, // 208: MOV
	{ "mov.a", 5 }, // 209: MOV_A
	{ "mov.aa", 6 }, // 210: MOV_AA
	{ "mov.d", 5 }, // 211: MOV_D
	{ "mov.u", 5 }, // 212: MOV_U
	{ "movh", 4 }, // 213: MOVH
	{ "movh.a", 6 }, // 214: MOVH_A
	{ "msub", 4 }, // 215: MSUB
	{ "msub.h", 6 }, // 216: MSUB_H
	{ "msub.q", 6 }, // 217: MSUB_Q
	{ "msub.u", 6 }, // 218: MSUB_U
	{ "msubad.h", 8 }, // 219: MSUBAD_H
	{ "msubadm.h", 9 }, // 220: MSUBADM_H
	{ "msubadms.h", 10 }, // 221: MSUBADMS_H
	{ "msubadr.h", 9 }, // 222: MSUBADR_H
	{ "msubadrs.h", 10 }, // 223: MSUBADRS_H
	{ "msubads.h", 9 }, // 224: MSUBADS_H
	{ "msubm.h", 7 }, // 225: MSUBM_H
	{ "msubms.h", 8 }, // 226: MSUBMS_H
	{ "msubr.h", 7 }, // 227: MSUBR_H
	{ "msubr.q", 7 }, // 228: MSUBR_Q
	{ "msubrs.h", 8 }, // 229: MSUBRS_H
	{ "msubrs.q", 8 }, // 230: MSUBRS_Q
	{ "msubs", 5 }, // 231: MSUBS
	{ "msubs.h", 7 }, // 232: MSUBS_H
	{ "msubs.q", 7 }, // 233: MSUBS_Q
	{ "msubs.u", 7 }, // 234: MSUBS_U
	{ "mtcr", 4 }, // 235: MTCR
	{ "mul", 3 }, // 236: MUL
	{ "mul.h", 5 }, // 237: MUL_H
	{ "mul.q", 5 }, // 238: MUL_Q
	{ "mul.u", 5 }, // 239: MUL_U
	{ "mulm.h", 6 }, // 240: MULM_H
	{ "mulms.h", 7 }, // 241: MULMS_H
	{ "mulr.h", 6 }, // 242: MULR_H
	{ "mulr.q", 6 }, // 243: MULR_Q
	{ "muls", 4 }, // 244: MULS
	{ "muls.u", 6 }, // 245: MULS_U
	{ "nand", 4 }, // 246: NAND
	{ "nand.t", 6 }, // 247: NAND_T
	{ "ne", 2 }, // 248: NE
	{ "ne.a", 4 }, // 249: NE_A
	{ "nez.a", 5 }, // 250: NEZ_A
	{ "nop", 3 }, // 251: NOP
	{ "nor", 3 }, // 252: NOR
	{ "nor.t", 5 }, // 253: NOR_T
	{ "not", 3 }, // 254: NOT
	{ "or", 2 }, // 255: OR
	{ "or.and.t", 8 }, // 256: OR_AND_T
	{ "or.andn.t", 9 }, // 257: OR_ANDN_T
	{ "or.eq", 5 }, // 258: OR_EQ
	{ "or.ge", 5 }, // 259: OR_GE
	{ "or.ge.u", 7 }, // 260: OR_GE_U
	{ "or.lt", 5 }, // 261: OR_LT
	{ "or.lt.u", 7 }, // 262: OR_LT_U
	{ "or.ne", 5 }, // 263: OR_NE
	{ "or.nor.t", 8 }, // 264: OR_NOR_T
	{ "or.or.t", 7 }, // 265: OR_OR_T
	{ "or.t", 4 }, // 266: OR_T
	{ "orn", 3 }, // 267: ORN
	{ "orn.t", 5 }, // 268: ORN_T
	{ "pack", 4 }, // 269: PACK
	{ "parity", 6 }, // 270: PARITY
	{ "restore", 7 }, // 271: RESTORE
	{ "ret", 3 }, // 272: RET
	{ "rfe", 3 }, // 273: RFE
	{ "rfm", 3 }, // 274: RFM
	{ "rslcx", 5 }, // 275: RSLCX
	{ "rstv", 4 }, // 276: RSTV
	{ "rsub", 4 }, // 277: RSUB
	{ "rsubs", 5 }, // 278: RSUBS
	{ "rsubs.u", 7 }, // 279: RSUBS_U
	{ "sat.b", 5 }, // 280: SAT_B
	{ "sat.bu", 6 }, // 281: SAT_BU
	{ "sat.h", 5 }, // 282: SAT_H
	{ "sat.hu", 6 }, // 283: SAT_HU
	{ "sel", 3 }, // 284: SEL
	{ "seln", 4 }, // 285: SELN
	{ "sh", 2 }, // 286: SH
	{ "sh.and.t", 8 }, // 287: SH_AND_T
	{ "sh.andn.t", 9 }, // 288: SH_ANDN_T
	{ "sh.eq", 5 }, // 289: SH_EQ
	{ "sh.ge", 5 }, // 290: SH_GE
	{ "sh.ge.u", 7 }, // 291: SH_GE_U
	{ "sh.h", 4 }, // 292: SH_H
	{ "sh.lt", 5 }, // 293: SH_LT
	{ "sh.lt.u", 7 }, // 294: SH_LT_U
	{ "sh.nand.t", 9 }, // 295: SH_NAND_T
	{ "sh.ne", 5 }, // 296: SH_NE
	{ "sh.nor.t", 8 }, // 297: SH_NOR_T
	{ "sh.or.t", 7 }, // 298: SH_OR_T
	{ "sh.orn.t", 8 }, // 299: SH_ORN_T
	{ "sh.xnor.t", 9 }, // 300: SH_XNOR_T
	{ "sh.xor.t", 8 }, // 301: SH_XOR_T
	{ "sha", 3 }, // 302: SHA
	{ "sha.h", 5 }, // 303: SHA_H
	{ "shas", 4 }, // 304: SHAS
	{ "st.a", 4 }, // 305: ST_A
	{ "st.b", 4 }, // 306: ST_B
	{ "st.d", 4 }, // 307: ST_D
	{ "st.da", 5 }, // 308: ST_DA
	{ "st.h", 4 }, // 309: ST_H
	{ "st.q", 4 }, // 310: ST_Q
	{ "st.t", 4 }, // 311: ST_T
	{ "st.w", 4 }, // 312: ST_W
	{ "stlcx", 5 }, // 313: STLCX
	{ "stucx", 5 }, // 314: STUCX
	{ "sub", 3 }, // 315: SUB
	{ "sub.a", 5 }, // 316: SUB_A
	{ "sub.b", 5 }, // 317: SUB_B
	{ "sub.h", 5 }, // 318: SUB_H
	{ "subc", 4 }, // 319: SUBC
	{ "subs", 4 }, // 320: SUBS
	{ "subs.h", 6 }, // 321: SUBS_H
	{ "subs.hu", 7 }, // 322: SUBS_HU
	{ "subs.u", 6 }, // 323: SUBS_U
	{ "subx", 4 }, // 324: SUBX
	{ "svlcx", 5 }, // 325: SVLCX
	{ "swap.w", 6 }, // 326: SWAP_W
	{ "swapmsk.w", 9 }, // 327: SWAPMSK_W
	{ "syscall", 7 }, // 328: SYSCALL
	{ "trapsv", 6 }, // 329: TRAPSV
	{ "trapv", 5 }, // 330: TRAPV
	{ "unpack", 6 }, // 331: UNPACK
	{ "wait", 4 }, // 332: WAIT
	{ "xnor", 4 }, // 333: XNOR
	{ "xnor.t", 6 }, // 334: XNOR_T
	{ "xor", 3 }, // 335: XOR
	{ "xor.eq", 6 }, // 336: XOR_EQ
	{ "xor.ge", 6 }, // 337: XOR_GE
	{ "xor.ge.u", 8 }, // 338: XOR_GE_U
	{ "xor.lt", 6 }, // 339: XOR_LT
	{ "xor.lt.u", 8 }, // 340: XOR_LT_U
	{ "xor.ne", 6 }, // 341: XOR_NE
	{ "xor.t", 5 }, // 342: XOR_T
	{ "~[invalid~entry~mnem]~", 22 }
}; /* strings */

mnems_e toMnem(StringView s) {
	return (mnems_e) ConstStringMap::fromString(s, mnem_strings, (uintn_t) NENTRIES);
}
StringView mnemToString(uintn_t val) {
	return ConstStringMap::toString(val, mnem_strings, (uintn_t) NENTRIES);
}

} } /* namespaces */

