#ifndef RISC_V_ISA_REGISTER_FILE_HPP
#define RISC_V_ISA_REGISTER_FILE_HPP


namespace risc_v_isa {
    class RegisterFile {
    private:
#if defined(__RVC__)
        static constexpr usize GENERAL_PURPOSE_NUM = 16;
#elif defined(__RV32I__) || defined(__RV64I__) || defined(__RV128I__)
        static constexpr usize GENERAL_PURPOSE_NUM = 32;
#endif // defined(__RV32I__) || defined(__RV64I__) || defined(__RV128I__)
        XLenT pc;
        XLenT x[GENERAL_PURPOSE_NUM];

    public:
#if defined(__RV32I__) || defined(__RV64I__) || defined(__RV128I__) || defined(__RVC__)
        static constexpr usize ZERO = 0;
        static constexpr usize RA = 1;
        static constexpr usize SP = 2;
        static constexpr usize GP = 3;
        static constexpr usize TP = 4;
        static constexpr usize T0 = 5;
        static constexpr usize T1 = 6;
        static constexpr usize T2 = 7;
        static constexpr usize S0 = 8;
        static constexpr usize FP = 8;
        static constexpr usize S1 = 9;
        static constexpr usize A0 = 10;
        static constexpr usize A1 = 11;
        static constexpr usize A2 = 12;
        static constexpr usize A3 = 13;
        static constexpr usize A4 = 14;
        static constexpr usize A5 = 15;
#endif // defined(__RV32I__) || defined(__RV64I__) || defined(__RV128I__) || defined(__RVC__)
#if defined(__RV32I__) || defined(__RV64I__) || defined(__RV128I__)
        static constexpr usize A6 = 16;
        static constexpr usize A7 = 17;
        static constexpr usize S2 = 18;
        static constexpr usize S3 = 19;
        static constexpr usize S4 = 20;
        static constexpr usize S5 = 21;
        static constexpr usize S6 = 22;
        static constexpr usize S7 = 23;
        static constexpr usize S8 = 24;
        static constexpr usize S9 = 25;
        static constexpr usize S10 = 26;
        static constexpr usize S11 = 27;
        static constexpr usize T3 = 28;
        static constexpr usize T4 = 29;
        static constexpr usize T5 = 30;
        static constexpr usize T6 = 31;
#endif // defined(__RV32I__) || defined(__RV64I__) || defined(__RV128I__)

        RegisterFile() : pc{}, x{} {}

        void set_pc(XLenT val) { pc = val; }

        XLenT get_pc() const { return pc; }

        void inc_pc(XLenT offset) { pc += offset; }

        void set_x(usize index, XLenT val) { if (index != 0) x[index] = val; }

        XLenT get_x(usize index) const { return x[index]; }

    };
}


#endif //RISC_V_ISA_REGISTER_FILE_HPP