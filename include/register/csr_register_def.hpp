#ifndef RISCV_ISA_CSR_REGISTER_DEF_HPP
#define RISCV_ISA_CSR_REGISTER_DEF_HPP


#include "range_def.hpp"


#define _riscv_isa_declare_csr_n(func, NAME, name, base, n) \
    func(NAME##n, name##n, base + n)

#define _riscv_isa_csr_reg_range(begin, end, func, NAME, name, base) \
    _riscv_isa_range(begin, end, _riscv_isa_declare_csr_n, func, NAME, name, base)

#define _riscv_isa_declare_csr_pos_n(func, NAME, name, POS, pos, base, n) \
    func(NAME##n##POS, name##n##pos, base + n)

#define _riscv_isa_csr_reg_pos_range(begin, end, func, NAME, name, POS, pos, base) \
    _riscv_isa_range(begin, end, _riscv_isa_declare_csr_pos_n, func, NAME, name, POS, pos, base)

#if __RV_BIT_WIDTH__ == 32
#define _riscv_isa_machine_status_32_csr_map(func) \
    func(MSTATUSH, mstatush, 0x310)
#else
#define _riscv_isa_machine_status_32_csr_map(func)
#endif

#if __RV_BIT_WIDTH__ == 32
#define _riscv_isa_pmpcfg1_32_csr_map(func) \
    func(PMPCFG1, pmpcfg1, 0x3A1)
#else
#define _riscv_isa_pmpcfg1_32_csr_map(func)
#endif

#if __RV_BIT_WIDTH__ == 32
#define _riscv_isa_pmpcfg3_32_csr_map(func) \
    func(PMPCFG3, pmpcfg3, 0x3A3)
#else
#define _riscv_isa_pmpcfg3_32_csr_map(func)
#endif

#if __RV_BIT_WIDTH__ == 32
#define _riscv_isa_hypervisor_mode_32_csr_map(func) \
    func(HTIMEDELTAH, htimedeltah, 0x615)
#else
#define _riscv_isa_hypervisor_mode_32_csr_map(func)
#endif

#if __RV_BIT_WIDTH__ == 32
#define _riscv_isa_machine_mode_32_csr_map(func) \
    func(MCYCLEH, mcycleh, 0xB80) \
    func(MINSTRETH, minstreth, 0xB82) \
    _riscv_isa_csr_reg_pos_range(3, 32, func, MHPMCOUNTER, mhpmcounter, H, h, 0xB80)
#else
#define _riscv_isa_machine_mode_32_csr_map(func, func_range, func_pos_range)
#endif

#if __RV_BIT_WIDTH__ == 32
#define _riscv_isa_user_mode_32_csr_map(func) \
    func(CYCLEH, cycleh, 0xC80) \
    func(TIMEH, timeh, 0xC81) \
    func(INSTRETH, instreth, 0xC82) \
    _riscv_isa_csr_reg_pos_range(3, 32, func, HPMCOUNTER, hpmcounter, H, h, 0xC80)
#else
#define _riscv_isa_user_mode_32_csr_map(func, func_range, func_pos_range)
#endif

#if defined(__RV_EXTENSION_N__)
#define _riscv_isa_ustatus_csr_map(func) \
    func(USTATUS, ustatus, 0x000)
#define _riscv_isa_user_extension_n_csr_map(func) \
    func(UIE, uie, 0x004) \
    func(UTVEC, utvec, 0x005) \
    func(USCRATCH, uscratch, 0x040) \
    func(UEPC, uepc, 0x041) \
    func(UCAUSE, ucause, 0x042) \
    func(UTVAL, utval, 0x043) \
    func(UIP, uip, 0x044)
#else
#define _riscv_isa_ustatus_csr_map(func)
#define _riscv_isa_user_extension_n_csr_map(func)
#endif

#if defined(__RV_USER_MODE__) || defined(__RV_SUPERVISOR_MODE__)
#define _riscv_isa_counter_csr_map(func) \
    func(CYCLE, cycle, 0xC00) \
    func(TIME, time, 0xC01) \
    func(INSTRET, instret, 0xC02) \
    _riscv_isa_csr_reg_range(3, 32, func, HPMCOUNTER, hpmcounter, 0xC00) \
    _riscv_isa_user_mode_32_csr_map(func)
#else
#define _riscv_isa_counter_csr_map(func)
#endif

#if defined(__RV_SUPERVISOR_MODE__)
#define _riscv_isa_supervisor_mode_csr_map(func) \
    func(SSTATUS, sstatus, 0x100) \
    func(SEDELEG, sedeleg, 0x102) \
    func(SIDELEG, sideleg, 0x103) \
    func(SIE, sie, 0x104) \
    func(STVEC, stvec, 0x105) \
    func(SCOUNTEREN, scounteren, 0x106) \
    func(SSCRATCH, sscratch, 0x140) \
    func(SEPC, sepc, 0x141) \
    func(SCAUSE, scause, 0x142) \
    func(STVAL, stval, 0x143) \
    func(SIP, sip, 0x144) \
    func(SATP, satp, 0x180)
#else
#define _riscv_isa_supervisor_mode_csr_map(func)
#endif

#if defined(__RV_HYPERVISOR_MODE__)
#define _riscv_isa_hypervisor_mode_csr_map(func) \
    func(HSTATUS, hstatus, 0x600) \
    func(HEDELEG, hedeleg, 0x602) \
    func(HIDELEG, hideleg, 0x603) \
    func(HIE, hie, 0x604) \
    func(HTIMEDELTA, htimedelta, 0x605) \
    func(HCOUNTEREN, hcounteren, 0x606) \
    func(HGEIE, hgeie, 0x607) \
    _riscv_isa_hypervisor_mode_32_csr_map(func) \
    func(HTVAL, htval, 0x643) \
    func(HIP, hip, 0x644) \
    func(HTINST, htinst, 0x64A) \
    func(HGATP, hgatp, 0x680)
#define _riscv_isa_hypervisor_mode_virtual_supervisor_csr_map(func) \
    func(VSSTATUS, vsstatus, 0x200) \
    func(VSIE, vsie, 0x204) \
    func(VSTVEC, vstvec, 0x205) \
    func(VSSCRATCH, vsscratch, 0x240) \
    func(VSEPC, vsepc, 0x241) \
    func(VSCAUSE, vscause, 0x242) \
    func(VSTVAL, vstval, 0x243) \
    func(VSIP, vsip, 0x244) \
    func(VSATP, vsatp, 0x280)
#define _riscv_isa_hgeip_csr_map(func) \
    func(HGEIP, hgeip, 0xE07)
#define _riscv_isa_hypervisor_mode_addition_csr_map(func) \
    func(MTINST, mtinst, 0x34A) \
    func(MTVAL2, mtval2, 0x34B)
#else
#define _riscv_isa_hypervisor_mode_csr_map(func)
#define _riscv_isa_hypervisor_mode_virtual_supervisor_csr_map(func)
#define _riscv_isa_hgeip_csr_map(func)
#define _riscv_isa_hypervisor_mode_addition_csr_map(func)
#endif

#if defined(__RV_DEBUG_MODE__)
#define _riscv_isa_debug_mode_csr_map(func) \
    func(TSELECT, tselect, 0x7A0) \
    func(TDATA1, tdata1, 0x7A1) \
    func(TDATA2, tdata2, 0x7A2) \
    func(TDATA3, tdata3, 0x7A3) \
    func(DCSAR, dcsar, 0x7B0) \
    func(DPC, dpc, 0x7B1) \
    func(DSCRATCH0, dscratch0, 0x7B2) \
    func(DSCRATCH1, dscratch1, 0x7B3)
#else
#define _riscv_isa_debug_mode_csr_map(func)
#endif

#if defined(__RV_FLOAT_POINT__)
#define _riscv_isa_float_point_csr_map(func) \
    func(FFLAGS, fflags, 0x001) \
    func(FRM, frm, 0x002) \
    func(FCSR, fcsr, 0x003)
#else
#define _riscv_isa_float_point_csr_map(func)
#endif

#define riscv_isa_csr_reg_map(func) \
    _riscv_isa_ustatus_csr_map(func) \
    _riscv_isa_float_point_csr_map(func) \
    _riscv_isa_user_extension_n_csr_map(func) \
    _riscv_isa_supervisor_mode_csr_map(func) \
    _riscv_isa_hypervisor_mode_virtual_supervisor_csr_map(func) \
    func(MSTATUS, mstatus, 0x300) \
    func(MISA, misa, 0x301) \
    func(MEDELEG, medeleg, 0x302) \
    func(MIDELEG, mideleg, 0x303) \
    func(MIE, mie, 0x304) \
    func(MTVEC, mtvec, 0x305) \
    func(MCOUNTEREN, mcounteren, 0x306) \
    _riscv_isa_machine_status_32_csr_map(func) \
    func(MCOUNTINHIBIT, mcountinhibit, 0x320) \
    _riscv_isa_csr_reg_range(3, 32, func, MHPMEVENT, mhpmevent, 0x320) \
    func(MSCRATCH, mscratch, 0x340) \
    func(MEPC, mepc, 0x341) \
    func(MCAUSE, mcause, 0x342) \
    func(MTVAL, mtval, 0x343) \
    func(MIP, mip, 0x344) \
    _riscv_isa_hypervisor_mode_addition_csr_map(func) \
    func(PMPCFG0, pmpcfg0, 0x3A0) \
    _riscv_isa_pmpcfg1_32_csr_map(func) \
    func(PMPCFG2, pmpcfg2, 0x3A2) \
    _riscv_isa_pmpcfg3_32_csr_map(func) \
    _riscv_isa_csr_reg_range(0, 16, func, PMPADDR, pmpaddr, 0x3B0) \
    _riscv_isa_hypervisor_mode_csr_map(func) \
    _riscv_isa_debug_mode_csr_map(func) \
    func(MCYCLE, mcycle, 0xB00) \
    func(MINSTRET, minstret, 0xB02) \
    _riscv_isa_csr_reg_range(3, 32, func, MHPMCOUNTER, mhpmcounter, 0xB00) \
    _riscv_isa_machine_mode_32_csr_map(func) \
    _riscv_isa_counter_csr_map(func) \
    _riscv_isa_hgeip_csr_map(func) \
    func(MVENDORID, mvendorid, 0xF11) \
    func(MARCHID, marchid, 0xF12) \
    func(MIMPID, mimpid, 0xF13) \
    func(MHARTID, mhartid,  0xF14)

#endif //RISCV_ISA_CSR_REGISTER_DEF_HPP
