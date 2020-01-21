#ifndef RISC_V_ISA_RV64M_HPP
#define RISC_V_ISA_RV64M_HPP


#include "instruction.hpp"


#if defined(__RV_EXTENSION_M__) && defined(__RV_64_BIT__)
namespace risc_v_isa {
    namespace {
        struct MULW { static i32 op(i32 a, i32 b) { return a * b; } };

        struct DIVW {
            static i32 op(i32 a, i32 b) {
                if (b == 0) return -1;
                else if (a == XLenTMin && b == -1) return XLenTMin;
                return a / b;
            }
        };

        struct DIVUW { static i32 op(u32 a, u32 b) { return b == 0 ? -1 : a / b; } };

        struct REMW {
            static i32 op(i32 a, i32 b) {
                if (b == 0) return a;
                else if (a == XLenTMin && b == -1) return 0;
                return a % b;
            }
        };

        struct REMUW { static i32 op(u32 a, u32 b) { return b == 0 ? a : a % b; } };
    }

    class InstructionMulDivWSet : public InstructionArithRegWSet {
    public:
        static constexpr InnerT FUNC_7 = 0b0000001;
    };

    class MULWInst : public InstructionMulDivWSet {
    public:
        static constexpr InnerT FUNCT_3 = 0b000;

        template <typename RegT>
        void operator()(RegT &reg) { operate_on<MULW>(reg); }

        friend std::ostream &operator<<(std::ostream &stream, const MULWInst &inst) {
            stream << "\tmulw\tx" << inst.get_rd() << ", x" << inst.get_rs1() << ", x" << inst.get_rs2();
            return stream;
        }
    };

    class DIVWInst : public InstructionMulDivWSet {
    public:
        static constexpr InnerT FUNCT_3 = 0b100;

        template <typename RegT>
        void operator()(RegT &reg) { operate_on<DIVW>(reg); }

        friend std::ostream &operator<<(std::ostream &stream, const DIVWInst &inst) {
            stream << "\tdivw\tx" << inst.get_rd() << ", x" << inst.get_rs1() << ", x" << inst.get_rs2();
            return stream;
        }
    };

    class DIVUWInst : public InstructionMulDivWSet {
    public:
        static constexpr InnerT FUNCT_3 = 0b101;

        template <typename RegT>
        void operator()(RegT &reg) { operate_on<DIVUW>(reg); }

        friend std::ostream &operator<<(std::ostream &stream, const DIVUWInst &inst) {
            stream << "\tdivuw\tx" << inst.get_rd() << ", x" << inst.get_rs1() << ", x" << inst.get_rs2();
            return stream;
        }
    };

    class REMWInst : public InstructionMulDivWSet {
    public:
        static constexpr InnerT FUNCT_3 = 0b110;

        template <typename RegT>
        void operator()(RegT &reg) { operate_on<REMW>(reg); }

        friend std::ostream &operator<<(std::ostream &stream, const REMWInst &inst) {
            stream << "\tremw\tx" << inst.get_rd() << ", x" << inst.get_rs1() << ", x" << inst.get_rs2();
            return stream;
        }
    };

    class REMUWInst : public InstructionMulDivWSet {
    public:
        static constexpr InnerT FUNCT_3 = 0b111;

        template <typename RegT>
        void operator()(RegT &reg) { operate_on<REMUW>(reg); }

        friend std::ostream &operator<<(std::ostream &stream, const REMUWInst &inst) {
            stream << "\tremuw\tx" << inst.get_rd() << ", x" << inst.get_rs1() << ", x" << inst.get_rs2();
            return stream;
        }
    };


}
#endif // defined(__RV_EXTENSION_M__) && defined(__RV_64_BIT__)


#endif //RISC_V_ISA_RV64M_HPP