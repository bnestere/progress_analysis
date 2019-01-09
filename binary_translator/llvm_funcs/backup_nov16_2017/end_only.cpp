// Generated by llvm2cpp - DO NOT MODIFY!
#include <type_traits>

#include "llvm/Pass.h"
#include "llvm/PassManager.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/APInt.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/CallingConv.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/IRPrintingPasses.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/CFG.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/SourceMgr.h"

using namespace llvm;


Function* define_pp_end(Module *mod, GlobalVariable *gvar_array_active_pps) {

  // Type Definitions
  std::vector<Type*>FuncTy_0_args;
  FuncTy_0_args.push_back(IntegerType::get(mod->getContext(), 64));
  FunctionType* FuncTy_0 = FunctionType::get(
      /*Result=*/Type::getVoidTy(mod->getContext()),
      /*Params=*/FuncTy_0_args,
      /*isVarArg=*/false);

  PointerType* PointerTy_1 = PointerType::get(IntegerType::get(mod->getContext(), 64), 0);

  PointerType* PointerTy_2 = PointerType::get(IntegerType::get(mod->getContext(), 32), 0);

  std::vector<Type*>FuncTy_4_args;
  FunctionType* FuncTy_4 = FunctionType::get(
      /*Result=*/IntegerType::get(mod->getContext(), 32),
      /*Params=*/FuncTy_4_args,
      /*isVarArg=*/false);

  PointerType* PointerTy_3 = PointerType::get(FuncTy_4, 0);

  ArrayType* ArrayTy_6 = ArrayType::get(IntegerType::get(mod->getContext(), 64), 1024);

  PointerType* PointerTy_5 = PointerType::get(ArrayTy_6, 0);

  PointerType* PointerTy_7 = PointerType::get(IntegerType::get(mod->getContext(), 8), 0);

  ArrayType* ArrayTy_9 = ArrayType::get(IntegerType::get(mod->getContext(), 8), 18);

  PointerType* PointerTy_8 = PointerType::get(ArrayTy_9, 0);

  std::vector<Type*>FuncTy_11_args;
  FuncTy_11_args.push_back(PointerTy_7);
  FunctionType* FuncTy_11 = FunctionType::get(
      /*Result=*/IntegerType::get(mod->getContext(), 32),
      /*Params=*/FuncTy_11_args,
      /*isVarArg=*/true);

  PointerType* PointerTy_10 = PointerType::get(FuncTy_11, 0);


  // Function Declarations

  Function* func_getpid = mod->getFunction("getpid");
  if (!func_getpid) {
    func_getpid = Function::Create(
        /*Type=*/FuncTy_4,
        /*Linkage=*/GlobalValue::ExternalLinkage,
        /*Name=*/"getpid", mod); // (external, no body)
    func_getpid->setCallingConv(CallingConv::C);
  }
  AttributeSet func_getpid_PAL;
  {
    SmallVector<AttributeSet, 4> Attrs;
    AttributeSet PAS;
    {
      AttrBuilder B;
      B.addAttribute(Attribute::NoUnwind);
      PAS = AttributeSet::get(mod->getContext(), ~0U, B);
    }

    Attrs.push_back(PAS);
    func_getpid_PAL = AttributeSet::get(mod->getContext(), Attrs);

  }
  func_getpid->setAttributes(func_getpid_PAL);

  Function* func_printf = mod->getFunction("printf");
  if (!func_printf) {
    func_printf = Function::Create(
        /*Type=*/FuncTy_11,
        /*Linkage=*/GlobalValue::ExternalLinkage,
        /*Name=*/"printf", mod); // (external, no body)
    func_printf->setCallingConv(CallingConv::C);
  }
  AttributeSet func_printf_PAL;
  {
    SmallVector<AttributeSet, 4> Attrs;
    AttributeSet PAS;
    {
      AttrBuilder B;
      PAS = AttributeSet::get(mod->getContext(), ~0U, B);
    }

    Attrs.push_back(PAS);
    func_printf_PAL = AttributeSet::get(mod->getContext(), Attrs);

  }
  func_printf->setAttributes(func_printf_PAL);

  // Global Variable Declarations

//  GlobalVariable* gvar_array_active_pps = new GlobalVariable(/*Module=*/*mod, 
//      /*Type=*/ArrayTy_6,
//      /*isConstant=*/false,
//      /*Linkage=*/GlobalValue::InternalLinkage,
//      /*Initializer=*/0, // has initializer, specified below
//      /*Name=*/"active_pps");
//  gvar_array_active_pps->setAlignment(16);

  GlobalVariable* gvar_array__str = new GlobalVariable(/*Module=*/*mod, 
      /*Type=*/ArrayTy_9,
      /*isConstant=*/true,
      /*Linkage=*/GlobalValue::PrivateLinkage,
      /*Initializer=*/0, // has initializer, specified below
      /*Name=*/".str");
  gvar_array__str->setAlignment(1);

  // Constant Definitions
  ConstantInt* const_int32_12 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("1"), 10));
  ConstantInt* const_int32_13 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("1023"), 10));
  ConstantInt* const_int64_14 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("0"), 10));
//  ConstantAggregateZero* const_array_15 = ConstantAggregateZero::get(ArrayTy_6);
  ConstantInt* const_int32_16 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("0"), 10));
  std::vector<Constant*> const_ptr_17_indices;
  const_ptr_17_indices.push_back(const_int32_16);
  const_ptr_17_indices.push_back(const_int32_16);
  Constant* const_ptr_17 = ConstantExpr::getGetElementPtr(gvar_array__str, const_ptr_17_indices);
  Constant *const_array_18 = ConstantDataArray::getString(mod->getContext(), "Ending pp id %ld\x0A", true);

  // Global Variable Definitions
  //gvar_array_active_pps->setInitializer(const_array_15);
  gvar_array__str->setInitializer(const_array_18);

  Function* func_pp_end = mod->getFunction("pp_end");
  if (!func_pp_end) {
    func_pp_end = Function::Create(
        /*Type=*/FuncTy_0,
        /*Linkage=*/GlobalValue::ExternalLinkage,
        /*Name=*/"pp_end", mod); 
    func_pp_end->setCallingConv(CallingConv::C);
  }
  AttributeSet func_pp_end_PAL;
  {
    SmallVector<AttributeSet, 4> Attrs;
    AttributeSet PAS;
    {
      AttrBuilder B;
      B.addAttribute(Attribute::NoUnwind);
      B.addAttribute(Attribute::UWTable);
      PAS = AttributeSet::get(mod->getContext(), ~0U, B);
    }

    Attrs.push_back(PAS);
    func_pp_end_PAL = AttributeSet::get(mod->getContext(), Attrs);

  }
  func_pp_end->setAttributes(func_pp_end_PAL);
  Function::arg_iterator args = func_pp_end->arg_begin();
  Value* int64_pp_id = args++;
  int64_pp_id->setName("pp_id");

  BasicBlock* label_entry = BasicBlock::Create(mod->getContext(), "entry",func_pp_end,0);
  BasicBlock* label_land_lhs_true = BasicBlock::Create(mod->getContext(), "land.lhs.true",func_pp_end,0);
  BasicBlock* label_if_then = BasicBlock::Create(mod->getContext(), "if.then",func_pp_end,0);
  BasicBlock* label_if_end = BasicBlock::Create(mod->getContext(), "if.end",func_pp_end,0);

  // Block entry (label_entry)
  AllocaInst* ptr_pp_id_addr = new AllocaInst(IntegerType::get(mod->getContext(), 64), "pp_id.addr", label_entry);
  ptr_pp_id_addr->setAlignment(8);
  AllocaInst* ptr_pid = new AllocaInst(IntegerType::get(mod->getContext(), 32), "pid", label_entry);
  ptr_pid->setAlignment(4);
  StoreInst* void_19 = new StoreInst(int64_pp_id, ptr_pp_id_addr, false, label_entry);
  void_19->setAlignment(8);
  CallInst* int32_call = CallInst::Create(func_getpid, "call", label_entry);
  int32_call->setCallingConv(CallingConv::C);
  int32_call->setTailCall(false);
  AttributeSet int32_call_PAL;
  {
    SmallVector<AttributeSet, 4> Attrs;
    AttributeSet PAS;
    {
      AttrBuilder B;
      B.addAttribute(Attribute::NoUnwind);
      PAS = AttributeSet::get(mod->getContext(), ~0U, B);
    }

    Attrs.push_back(PAS);
    int32_call_PAL = AttributeSet::get(mod->getContext(), Attrs);

  }
  int32_call->setAttributes(int32_call_PAL);

  BinaryOperator* int32_and = BinaryOperator::Create(Instruction::And, int32_call, const_int32_13, "and", label_entry);
  StoreInst* void_20 = new StoreInst(int32_and, ptr_pid, false, label_entry);
  void_20->setAlignment(4);
  LoadInst* int64_21 = new LoadInst(ptr_pp_id_addr, "", false, label_entry);
  int64_21->setAlignment(8);
  ICmpInst* int1_cmp = new ICmpInst(*label_entry, ICmpInst::ICMP_SGT, int64_21, const_int64_14, "cmp");
  BranchInst::Create(label_land_lhs_true, label_if_end, int1_cmp, label_entry);

  // Block land.lhs.true (label_land_lhs_true)
  LoadInst* int32_23 = new LoadInst(ptr_pid, "", false, label_land_lhs_true);
  int32_23->setAlignment(4);
  CastInst* int64_idxprom = new SExtInst(int32_23, IntegerType::get(mod->getContext(), 64), "idxprom", label_land_lhs_true);
  std::vector<Value*> ptr_arrayidx_indices;
  ptr_arrayidx_indices.push_back(const_int32_16);
  ptr_arrayidx_indices.push_back(int64_idxprom);
  Instruction* ptr_arrayidx = GetElementPtrInst::Create(gvar_array_active_pps, ptr_arrayidx_indices, "arrayidx", label_land_lhs_true);
  LoadInst* int64_24 = new LoadInst(ptr_arrayidx, "", false, label_land_lhs_true);
  int64_24->setAlignment(8);
  LoadInst* int64_25 = new LoadInst(ptr_pp_id_addr, "", false, label_land_lhs_true);
  int64_25->setAlignment(8);
  ICmpInst* int1_cmp1 = new ICmpInst(*label_land_lhs_true, ICmpInst::ICMP_EQ, int64_24, int64_25, "cmp1");
  BranchInst::Create(label_if_then, label_if_end, int1_cmp1, label_land_lhs_true);

  // Block if.then (label_if_then)
  LoadInst* int64_27 = new LoadInst(ptr_pp_id_addr, "", false, label_if_then);
  int64_27->setAlignment(8);
  std::vector<Value*> int32_call2_params;
  int32_call2_params.push_back(const_ptr_17);
  int32_call2_params.push_back(int64_27);
  CallInst* int32_call2 = CallInst::Create(func_printf, int32_call2_params, "call2", label_if_then);
  int32_call2->setCallingConv(CallingConv::C);
  int32_call2->setTailCall(false);
  AttributeSet int32_call2_PAL;
  int32_call2->setAttributes(int32_call2_PAL);

  LoadInst* int32_28 = new LoadInst(ptr_pid, "", false, label_if_then);
  int32_28->setAlignment(4);
  CastInst* int64_idxprom3 = new SExtInst(int32_28, IntegerType::get(mod->getContext(), 64), "idxprom3", label_if_then);
  std::vector<Value*> ptr_arrayidx4_indices;
  ptr_arrayidx4_indices.push_back(const_int32_16);
  ptr_arrayidx4_indices.push_back(int64_idxprom3);
  Instruction* ptr_arrayidx4 = GetElementPtrInst::Create(gvar_array_active_pps, ptr_arrayidx4_indices, "arrayidx4", label_if_then);
  StoreInst* void_29 = new StoreInst(const_int64_14, ptr_arrayidx4, false, label_if_then);
  void_29->setAlignment(8);
  BranchInst::Create(label_if_end, label_if_then);

  // Block if.end (label_if_end)
  ReturnInst::Create(mod->getContext(), label_if_end);
  return func_pp_end;
}