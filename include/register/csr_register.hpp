#ifndef RISCV_ISA_CSR_REGISTER_HPP
#define RISCV_ISA_CSR_REGISTER_HPP


#include "riscv_isa_utility.hpp"
#include "csr_register_def.hpp"


namespace riscv_isa {
    template<typename xlen>
    class CSRRegister {
    public:
        using XLenT = typename xlen::XLenT;
        using UXLenT = typename xlen::UXLenT;

        /// macro riscv_isa_csr_reg_map apply a macro to all csr registers.
        /// it will pass three arguments showed as below to the macro.
        ///
        /// NAME            name            num     info
        /// ----------------------------------------------------------------------------------------------------
#if defined(__RV_EXTENSION_N__)
        /// USTATUS,        ustatus,        0x000:  User status register.
#endif // defined(__RV_EXTENSION_N__)
#if defined(__RV_FLOAT_POINT__)
        /// FFLAGS,         fflags,         0x001:  Floating-Point Accrued Exceptions.
        /// FRM,            frm,            0x002:  Floating-Point Dynamic Rounding Mode.
        /// FCSR,           fcsr,           0x003:  Floating-Point Control and Status Register.
#endif // defined(__RV_FLOAT_POINT__)
#if defined(__RV_EXTENSION_N__)
        /// UIE,            uie,            0x004:  User interrupt-enable register.
        /// UTVEC,          utvec,          0x005:  User trap handler base address.
        /// USCRATCH,       uscratch,       0x040:  User trap handlers scratch register.
        /// UEPC,           uepc,           0x041:  User exception program counter.
        /// UCAUSE,         ucause,         0x042:  User trap cause.
        /// UTVAL,          utval,          0x043:  User bad address or instruction.
        /// UIP,            uip,            0x044:  User interrupt pending.
#endif // defined(__RV_EXTENSION_N__)
#if defined(__RV_SUPERVISOR_MODE__)
        /// SSTATUS,        sstatus,        0x100:  Supervisor status register.
#if defined(__RV_EXTENSION_N__)
        /// SEDELEG,        sedeleg,        0x102:  Supervisor exception delegation register.
        /// SIDELEG,        sideleg,        0x103:  Supervisor interrupt delegation register.
#endif // defined(__RV_EXTENSION_N__)
        /// SIE,            sie,            0x104:  Supervisor interrupt-enable register.
        /// STVEC,          stvec,          0x105:  Supervisor trap handler base address.
        /// SCOUNTEREN,     scounteren,     0x106:  Supervisor counter enable.
        /// SSCRATCH,       sscratch,       0x140:  Supervisor trap handlers scratch register.
        /// SEPC,           sepc,           0x141:  Supervisor exception program counter.
        /// SCAUSE,         scause,         0x142:  Supervisor trap cause.
        /// STVAL,          stval,          0x143:  Supervisor bad address or instruction.
        /// SIP,            sip,            0x144:  Supervisor interrupt pending.
        /// SATP,           satp,           0x180:  Supervisor address translation and protection.
#endif // defined(__RV_SUPERVISOR_MODE__)
#if defined(__RV_HYPERVISOR_MODE__)
        /// VSSTATUS,       vsstatus,       0x200:  Virtual supervisor status register.
        /// VSIE,           vsie,           0x204:  Virtual supervisor interrupt-enable register.
        /// VSTVEC,         vstvec,         0x205:  Virtual supervisor trap handler base address.
        /// VSSCRATCH,      vsscratch,      0x240:  Virtual supervisor scratch register.
        /// VSEPC,          vsepc,          0x241:  Virtual supervisor exception program counter.
        /// VSCAUSE,        vscause,        0x242:  Virtual supervisor trap cause.
        /// VSTVAL,         vstval,         0x243:  Virtual supervisor bad address or instruction.
        /// VSIP,           vsip,           0x244:  Virtual supervisor interrupt pending.
        /// VSATP,          vsatp,          0x280:  Virtual supervisor address translation and protection.
#endif // defined(__RV_HYPERVISOR_MODE__)
        /// MSTATUS,        mstatus,        0x300:  Machine status register.
        /// MISA,           misa,           0x301:  Machine ISA and extensions.
        /// MEDELEG,        medeleg,        0x302:  Machine exception delegation register.
        /// MIDELEG,        mideleg,        0x303:  Machine interrupt delegation register.
        /// MIE,            mie,            0x304:  Machine interrupt-enable register.
        /// MTVEC,          mtvec,          0x305:  Machine trap handler base address.
        /// MCOUNTEREN,     mcounteren,     0x306:  Machine counter enable.
#if __RV_BIT_WIDTH__ == 32
        /// MSTATUSH,       mstatush,       0x310:
#endif // __RV_BIT_WIDTH__ == 32
        /// MCOUNTINHIBIT,  mcountinhibit,  0x320:  Machine counter-inhibit register.
        /// MHPMEVENT3,     mhpmevent3,     0x323:  Machine performance-monitoring event selector.
        /// ...
        /// MHPMEVENT31,    mhpmevent31,    0x33F:
        /// MSCRATCH,       mscratch,       0x340:  Machine trap handlers Scratch register.
        /// MEPC,           mepc,           0x341:  Machine exception program counter.
        /// MCAUSE,         mcause,         0x342:  Machine trap cause.
        /// MTVAL,          mtval,          0x343:  Machine bad address or instruction.
        /// MIP,            mip,            0x344:  Machine interrupt pending.
#if defined(__RV_HYPERVISOR_MODE__)
        /// MTINST,         mtinst,         0x34A:  Machine trap instruction (transformed).
        /// MTVAL2,         mtval2,         0x34B:  Machine bad guest physical address.
#endif // defined(__RV_HYPERVISOR_MODE__)
        /// PMPCFG0,        pmpcfg0,        0x3A0:  Physical memory protection configuration.
#if __RV_BIT_WIDTH__ == 32
        /// PMPCFG1,        pmpcfg1,        0x3A1:
#endif // __RV_BIT_WIDTH__ == 32
        /// PMPCFG2,        pmpcfg2,        0x3A2:
#if __RV_BIT_WIDTH__ == 32
        /// PMPCFG3,        pmpcfg3,        0x3A3:
#endif // __RV_BIT_WIDTH__ == 32
        /// PMPADDR0,       pmpaddr0,       0x3B0:  Physical memory protection address register.
        /// ...
        /// PMPADDR15,      pmpaddr15,      0x3BF:
#if defined(__RV_HYPERVISOR_MODE__)
        /// HSTATUS,        hstatus,        0x600:  Hypervisor status register.
        /// HEDELEG,        hedeleg,        0x602:  Hypervisor exception delegation register.
        /// HIDELEG,        hideleg,        0x603:  Hypervisor interrupt delegation register.
        /// HIE,            hie,            0x604:  Hypervisor interrupt-enable register.
        /// HTIMEDELTA,     htimedelta,     0x605:  Delta for VS/VU-mode timer.
        /// HCOUNTEREN,     hcounteren,     0x606:  Hypervisor counter enable.
        /// HGEIE,          hgeie,          0x607:  Hypervisor guest external interrupt-enable register.
#if __RV_BIT_WIDTH__ == 32
        /// HTIMEDELTAH,    htimedeltah,    0x615:
#endif // __RV_BIT_WIDTH__ == 32
        /// HTVAL,          htval,          0x643:  Hypervisor bad guest physical address.
        /// HIP,            hip,            0x644:  Hypervisor interrupt pending.
        /// HTINST,         htinst,         0x64A:  Hypervisor trap instruction (transformed).
        /// HGATP,          hgatp,          0x680:  Hypervisor guest address translation and protection.
#endif // defined(__RV_HYPERVISOR_MODE__)
#if defined(__RV_DEBUG_MODE__)
        /// TSELECT,        tselect,        0x7A0:  Debug/Trace trigger register select.
        /// TDATA1,         tdata1,         0x7A1:  First Debug/Trace trigger data register.
        /// TDATA2,         tdata2,         0x7A2:  Second Debug/Trace trigger data register.
        /// TDATA3,         tdata3,         0x7A3:  Third Debug/Trace trigger data register.
        /// DCSAR,          dcsar,          0x7B0:  Debug control and status register.
        /// DPC,            dpc,            0x7B1:  Debug PC.
        /// DSCRATCH0,      dscratch0,      0x7B2:  Debug scratch register 0.
        /// DSCRATCH1,      dscratch1,      0x7B3:  Debug scratch register 1.
#endif // defined(__RV_DEBUG_MODE__)
        /// MCYCLE,         mcycle,         0xB00:  Machine cycle counter.
        /// MINSTRET,       minstret,       0xB02:  Machine instructions-retired counter.
        /// MHPMCOUNTER3,   mhpmcounter3,   0xB03:  Machine performance-monitoring counter.
        /// ...
        /// MHPMCOUNTER31,  mhpmcounter31,  0xB1F:
#if __RV_BIT_WIDTH__ == 32
        /// MCYCLEH,        mcycleh,        0xB80:
        /// MINSTRETH,      minstreth,      0xB82:
        /// MHPMCOUNTER3H,  mhpmcounter3h,  0xB83:
        /// ...
        /// MHPMCOUNTER31H, mhpmcounter31h, 0xB9F:
#endif // __RV_BIT_WIDTH__ == 32
#if defined(__RV_USER_MODE__) || defined(__RV_SUPERVISOR_MODE__)
        /// CYCLE,          cycle,          0xC00:  Cycle counter for RDCYCLE instruction.
        /// TIME,           time,           0xC01:  Timer for RDTIME instruction.
        /// INSTRET,        instret,        0xC02:  Instructions-retired counter for RDINSTRET instruction.
        /// HPMCOUNTER3,    hpmcounter3,    0xC03:  Performance-monitoring counter.
        /// ...
        /// HPMCOUNTER31,   hpmcounter31,   0xC1F:
#if __RV_BIT_WIDTH__ == 32
        /// CYCLEH,         cycleh,         0xC80:
        /// TIMEH,          timeh,          0xC81:
        /// INSTRETH,       instreth,       0xC82:
        /// HPMCOUNTER3H,   hpmcounter3h,   0xC83:
        /// ...
        /// HPMCOUNTER31H,  hpmcounter31h,  0xC9F:
#endif // __RV_BIT_WIDTH__ == 32
#endif // defined(__RV_USER_MODE__) || defined(__RV_SUPERVISOR_MODE__)
#if defined(__RV_HYPERVISOR_MODE__)
        /// HGEIP,          hgeip,          0xE07:  Hypervisor guest external interrupt pending.
#endif // defined(__RV_HYPERVISOR_MODE__)
        /// MVENDORID,      mvendorid,      0xF11:  Vendor ID.
        /// MARCHID,        marchid,        0xF12:  Architecture ID.
        /// MIMPID,         mimpid,         0xF13:  Implementation ID.
        /// MHARTID,        mhartid,        0xF14:  Hardware thread ID.

        /// following macro defines index for all csr.

        enum CSRRegIndex : usize {
#define _riscv_isa_declare_csr_index(NAME, name, num) \
            NAME,
            riscv_isa_csr_reg_map(_riscv_isa_declare_csr_index)
#undef _riscv_isa_declare_csr_index
            CSR_REGISTER_NUM,
        };

    private:
        static constexpr xlen_trait::UXLenT MISA_INIT =
                get_bits<UXLenT, 2, 0, xlen::XLEN - 2>(xlen::XLEN_INDEX - 4)
#ifdef __RV_EXTENSION_A__
                | bit_mask<UXLenT, 0>::val
#endif
#ifdef __RV_EXTENSION_B__
                | bit_mask<UXLenT, 1>::val
#endif
#ifdef __RV_EXTENSION_C__
                | bit_mask<UXLenT, 2>::val
#endif
#ifdef __RV_EXTENSION_D__
                | bit_mask<UXLenT, 3>::val
#endif
#ifdef __RV_BASE_E__
                | bit_mask<UXLenT, 4>::val
#endif
#ifdef __RV_EXTENSION_F__
                | bit_mask<UXLenT, 5>::val
#endif
#ifdef __RV_HYPERVISOR_MODE__
                | bit_mask<UXLenT, 7>::val
#endif
#ifdef __RV_BASE_I__
                | bit_mask<UXLenT, 8>::val
#endif
#ifdef __RV_EXTENSION_J__
                | bit_mask<UXLenT, 9>::val
#endif
#ifdef __RV_EXTENSION_L__
                | bit_mask<UXLenT, 11>::val
#endif
#ifdef __RV_EXTENSION_M__
                | bit_mask<UXLenT, 12>::val
#endif
#ifdef __RV_EXTENSION_N__
                | bit_mask<UXLenT, 13>::val
#endif
#ifdef __RV_EXTENSION_P__
                | bit_mask<UXLenT, 15>::val
#endif
#ifdef __RV_EXTENSION_Q__
                | bit_mask<UXLenT, 16>::val
#endif
#ifdef __RV_SUPERVISOR_MODE__
                | bit_mask<UXLenT, 18>::val
#endif
#ifdef __RV_EXTENSION_T__
                | bit_mask<UXLenT, 19>::val
#endif
#ifdef __RV_USER_MODE__
                | bit_mask<UXLenT, 20>::val
#endif
#ifdef __RV_EXTENSION_V__
                | bit_mask<UXLenT, 21>::val
#endif
#ifdef __RV_NON_STANDARD__
                | bit_mask<UXLenT, 23>::val
#endif
        ;

        xlen_trait::UXLenT inner[CSR_REGISTER_NUM];

    public:
        static constexpr usize READ_ONLY_BITS = 0b11;

        static usize get_read_write_bits(usize num) { return get_bits<usize, 12, 10>(num); }

        static PrivilegeLevel get_privilege_bits(usize num) {
            return static_cast<PrivilegeLevel>(get_bits<usize, 10, 8>(num));
        }

        CSRRegister(xlen_trait::UXLenT hart_id) { init_csr(hart_id); }

        void init_csr(xlen_trait::UXLenT hart_id) {
            for (usize i = 0; i < CSR_REGISTER_NUM; ++i) inner[i] = 0;

            inner[MISA] = MISA_INIT;
            inner[MVENDORID] = RISCV_VENDOR_ID;
            inner[MARCHID] = RISCV_ARCH_ID;
            inner[MIMPID] = RISCV_IMP_ID;
            inner[MHARTID] = hart_id;
        }

        /// following function transfer csr number to real index.
        /// if csr not defined, csr_num will be returned.

        static usize get_index(usize csr) {
            switch (csr) {
#define _riscv_isa_csr_get_index(NAME, name, num) \
                case num: \
                    return NAME;
                riscv_isa_csr_reg_map(_riscv_isa_csr_get_index)
#undef _riscv_isa_csr_get_index
                default:
                    return CSR_REGISTER_NUM;
            }
        }

        const UXLenT &operator[](usize index) const {
            if (index >= CSR_REGISTER_NUM) riscv_isa_abort("csr index out of boundary!");
            return inner[index];
        }

        UXLenT &operator[](usize index) {
            if (index >= CSR_REGISTER_NUM) riscv_isa_abort("csr index out of boundary!");
            return inner[index];
        }
    };
}


#endif // RISCV_ISA_CSR_REGISTER_HPP
