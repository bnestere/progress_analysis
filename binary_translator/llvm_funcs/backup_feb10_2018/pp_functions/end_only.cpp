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

  std::vector<Type*>FuncTy_8_args;
  FuncTy_8_args.push_back(IntegerType::get(mod->getContext(), 64));
  FunctionType* FuncTy_8 = FunctionType::get(
      /*Result=*/IntegerType::get(mod->getContext(), 64),
      /*Params=*/FuncTy_8_args,
      /*isVarArg=*/true);

  PointerType* PointerTy_7 = PointerType::get(FuncTy_8, 0);

  PointerType* PointerTy_9 = PointerType::get(IntegerType::get(mod->getContext(), 8), 0);

  ArrayType* ArrayTy_11 = ArrayType::get(IntegerType::get(mod->getContext(), 8), 24);

  PointerType* PointerTy_10 = PointerType::get(ArrayTy_11, 0);

  std::vector<Type*>FuncTy_13_args;
  FuncTy_13_args.push_back(PointerTy_9);
  FunctionType* FuncTy_13 = FunctionType::get(
      /*Result=*/Type::getVoidTy(mod->getContext()),
      /*Params=*/FuncTy_13_args,
      /*isVarArg=*/false);

  PointerType* PointerTy_12 = PointerType::get(FuncTy_13, 0);

  std::vector<Type*>FuncTy_15_args;
  FuncTy_15_args.push_back(IntegerType::get(mod->getContext(), 32));
  FunctionType* FuncTy_15 = FunctionType::get(
      /*Result=*/Type::getVoidTy(mod->getContext()),
      /*Params=*/FuncTy_15_args,
      /*isVarArg=*/false);

  PointerType* PointerTy_14 = PointerType::get(FuncTy_15, 0);


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

  Function* func_syscall = mod->getFunction("syscall");
  if (!func_syscall) {
    func_syscall = Function::Create(
        /*Type=*/FuncTy_8,
        /*Linkage=*/GlobalValue::ExternalLinkage,
        /*Name=*/"syscall", mod); // (external, no body)
    func_syscall->setCallingConv(CallingConv::C);
  }
  AttributeSet func_syscall_PAL;
  {
    SmallVector<AttributeSet, 4> Attrs;
    AttributeSet PAS;
    {
      AttrBuilder B;
      B.addAttribute(Attribute::NoUnwind);
      PAS = AttributeSet::get(mod->getContext(), ~0U, B);
    }

    Attrs.push_back(PAS);
    func_syscall_PAL = AttributeSet::get(mod->getContext(), Attrs);

  }
  func_syscall->setAttributes(func_syscall_PAL);

  Function* func_perror = mod->getFunction("perror");
  if (!func_perror) {
    func_perror = Function::Create(
        /*Type=*/FuncTy_13,
        /*Linkage=*/GlobalValue::ExternalLinkage,
        /*Name=*/"perror", mod); // (external, no body)
    func_perror->setCallingConv(CallingConv::C);
  }
  AttributeSet func_perror_PAL;
  {
    SmallVector<AttributeSet, 4> Attrs;
    AttributeSet PAS;
    {
      AttrBuilder B;
      PAS = AttributeSet::get(mod->getContext(), ~0U, B);
    }

    Attrs.push_back(PAS);
    func_perror_PAL = AttributeSet::get(mod->getContext(), Attrs);

  }
  func_perror->setAttributes(func_perror_PAL);

  Function* func_exit = mod->getFunction("exit");
  if (!func_exit) {
    func_exit = Function::Create(
        /*Type=*/FuncTy_15,
        /*Linkage=*/GlobalValue::ExternalLinkage,
        /*Name=*/"exit", mod); // (external, no body)
    func_exit->setCallingConv(CallingConv::C);
  }
  AttributeSet func_exit_PAL;
  {
    SmallVector<AttributeSet, 4> Attrs;
    AttributeSet PAS;
    {
      AttrBuilder B;
      B.addAttribute(Attribute::NoReturn);
      B.addAttribute(Attribute::NoUnwind);
      PAS = AttributeSet::get(mod->getContext(), ~0U, B);
    }

    Attrs.push_back(PAS);
    func_exit_PAL = AttributeSet::get(mod->getContext(), Attrs);

  }
  func_exit->setAttributes(func_exit_PAL);

  // Global Variable Declarations

//  GlobalVariable* gvar_array_active_pps = new GlobalVariable(/*Module=*/*mod, 
//      /*Type=*/ArrayTy_6,
//      /*isConstant=*/false,
//      /*Linkage=*/GlobalValue::InternalLinkage,
//      /*Initializer=*/0, // has initializer, specified below
//      /*Name=*/"active_pps");
//  gvar_array_active_pps->setAlignment(16);

  GlobalVariable* gvar_array__str = new GlobalVariable(/*Module=*/*mod, 
      /*Type=*/ArrayTy_11,
      /*isConstant=*/true,
      /*Linkage=*/GlobalValue::PrivateLinkage,
      /*Initializer=*/0, // has initializer, specified below
      /*Name=*/".str");
  gvar_array__str->setAlignment(1);

  // Constant Definitions
  ConstantInt* const_int32_16 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("1"), 10));
  ConstantInt* const_int32_17 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("1023"), 10));
  ConstantInt* const_int64_18 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("0"), 10));
//  ConstantAggregateZero* const_array_19 = ConstantAggregateZero::get(ArrayTy_6);
  ConstantInt* const_int32_20 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("0"), 10));
  ConstantInt* const_int64_21 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("330"), 10));
  std::vector<Constant*> const_ptr_22_indices;
  const_ptr_22_indices.push_back(const_int32_20);
  const_ptr_22_indices.push_back(const_int32_20);
  Constant* const_ptr_22 = ConstantExpr::getGetElementPtr(gvar_array__str, const_ptr_22_indices);
  Constant *const_array_23 = ConstantDataArray::getString(mod->getContext(), "Syscall pp_print failed", true);

  // Global Variable Definitions
//  gvar_array_active_pps->setInitializer(const_array_19);
  gvar_array__str->setInitializer(const_array_23);

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
  BasicBlock* label_if_then3 = BasicBlock::Create(mod->getContext(), "if.then3",func_pp_end,0);
  BasicBlock* label_if_end = BasicBlock::Create(mod->getContext(), "if.end",func_pp_end,0);
  BasicBlock* label_if_end6 = BasicBlock::Create(mod->getContext(), "if.end6",func_pp_end,0);

  // Block entry (label_entry)
  AllocaInst* ptr_pp_id_addr = new AllocaInst(IntegerType::get(mod->getContext(), 64), "pp_id.addr", label_entry);
  ptr_pp_id_addr->setAlignment(8);
  AllocaInst* ptr_pid = new AllocaInst(IntegerType::get(mod->getContext(), 32), "pid", label_entry);
  ptr_pid->setAlignment(4);
  AllocaInst* ptr_ret = new AllocaInst(IntegerType::get(mod->getContext(), 64), "ret", label_entry);
  ptr_ret->setAlignment(8);
  StoreInst* void_24 = new StoreInst(int64_pp_id, ptr_pp_id_addr, false, label_entry);
  void_24->setAlignment(8);
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

  BinaryOperator* int32_and = BinaryOperator::Create(Instruction::And, int32_call, const_int32_17, "and", label_entry);
  StoreInst* void_25 = new StoreInst(int32_and, ptr_pid, false, label_entry);
  void_25->setAlignment(4);
  LoadInst* int64_26 = new LoadInst(ptr_pp_id_addr, "", false, label_entry);
  int64_26->setAlignment(8);
  ICmpInst* int1_cmp = new ICmpInst(*label_entry, ICmpInst::ICMP_SGT, int64_26, const_int64_18, "cmp");
  BranchInst::Create(label_land_lhs_true, label_if_end6, int1_cmp, label_entry);

  // Block land.lhs.true (label_land_lhs_true)
  LoadInst* int32_28 = new LoadInst(ptr_pid, "", false, label_land_lhs_true);
  int32_28->setAlignment(4);
  CastInst* int64_idxprom = new SExtInst(int32_28, IntegerType::get(mod->getContext(), 64), "idxprom", label_land_lhs_true);
  std::vector<Value*> ptr_arrayidx_indices;
  ptr_arrayidx_indices.push_back(const_int32_20);
  ptr_arrayidx_indices.push_back(int64_idxprom);
  Instruction* ptr_arrayidx = GetElementPtrInst::Create(gvar_array_active_pps, ptr_arrayidx_indices, "arrayidx", label_land_lhs_true);
  LoadInst* int64_29 = new LoadInst(ptr_arrayidx, "", false, label_land_lhs_true);
  int64_29->setAlignment(8);
  LoadInst* int64_30 = new LoadInst(ptr_pp_id_addr, "", false, label_land_lhs_true);
  int64_30->setAlignment(8);
  ICmpInst* int1_cmp1 = new ICmpInst(*label_land_lhs_true, ICmpInst::ICMP_EQ, int64_29, int64_30, "cmp1");
  BranchInst::Create(label_if_then, label_if_end6, int1_cmp1, label_land_lhs_true);

  // Block if.then (label_if_then)
  LoadInst* int64_32 = new LoadInst(ptr_pp_id_addr, "", false, label_if_then);
  int64_32->setAlignment(8);
  std::vector<Value*> int64_call2_params;
  int64_call2_params.push_back(const_int64_21);
  int64_call2_params.push_back(int64_32);
  CallInst* int64_call2 = CallInst::Create(func_syscall, int64_call2_params, "call2", label_if_then);
  int64_call2->setCallingConv(CallingConv::C);
  int64_call2->setTailCall(false);
  AttributeSet int64_call2_PAL;
  {
    SmallVector<AttributeSet, 4> Attrs;
    AttributeSet PAS;
    {
      AttrBuilder B;
      B.addAttribute(Attribute::NoUnwind);
      PAS = AttributeSet::get(mod->getContext(), ~0U, B);
    }

    Attrs.push_back(PAS);
    int64_call2_PAL = AttributeSet::get(mod->getContext(), Attrs);

  }
  int64_call2->setAttributes(int64_call2_PAL);

  StoreInst* void_33 = new StoreInst(int64_call2, ptr_ret, false, label_if_then);
  void_33->setAlignment(8);
  LoadInst* int64_34 = new LoadInst(ptr_ret, "", false, label_if_then);
  int64_34->setAlignment(8);
  ICmpInst* int1_tobool = new ICmpInst(*label_if_then, ICmpInst::ICMP_NE, int64_34, const_int64_18, "tobool");
  BranchInst::Create(label_if_then3, label_if_end, int1_tobool, label_if_then);

  // Block if.then3 (label_if_then3)
  CallInst* void_36 = CallInst::Create(func_perror, const_ptr_22, "", label_if_then3);
  void_36->setCallingConv(CallingConv::C);
  void_36->setTailCall(false);
  AttributeSet void_36_PAL;
  void_36->setAttributes(void_36_PAL);

  CallInst* void_37 = CallInst::Create(func_exit, const_int32_16, "", label_if_then3);
  void_37->setCallingConv(CallingConv::C);
  void_37->setTailCall(false);
  AttributeSet void_37_PAL;
  {
    SmallVector<AttributeSet, 4> Attrs;
    AttributeSet PAS;
    {
      AttrBuilder B;
      B.addAttribute(Attribute::NoReturn);
      B.addAttribute(Attribute::NoUnwind);
      PAS = AttributeSet::get(mod->getContext(), ~0U, B);
    }

    Attrs.push_back(PAS);
    void_37_PAL = AttributeSet::get(mod->getContext(), Attrs);

  }
  void_37->setAttributes(void_37_PAL);

  new UnreachableInst(mod->getContext(), label_if_then3);

  // Block if.end (label_if_end)
  LoadInst* int32_39 = new LoadInst(ptr_pid, "", false, label_if_end);
  int32_39->setAlignment(4);
  CastInst* int64_idxprom4 = new SExtInst(int32_39, IntegerType::get(mod->getContext(), 64), "idxprom4", label_if_end);
  std::vector<Value*> ptr_arrayidx5_indices;
  ptr_arrayidx5_indices.push_back(const_int32_20);
  ptr_arrayidx5_indices.push_back(int64_idxprom4);
  Instruction* ptr_arrayidx5 = GetElementPtrInst::Create(gvar_array_active_pps, ptr_arrayidx5_indices, "arrayidx5", label_if_end);
  StoreInst* void_40 = new StoreInst(const_int64_18, ptr_arrayidx5, false, label_if_end);
  void_40->setAlignment(8);
  BranchInst::Create(label_if_end6, label_if_end);

  // Block if.end6 (label_if_end6)
  ReturnInst::Create(mod->getContext(), label_if_end6);
  return func_pp_end;
}
