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


Function* define_pp_begin(Module *mod, GlobalVariable *gvar_array_active_pps) {

  // Type Definitions
  std::vector<Type*>FuncTy_0_args;
  StructType *StructTy_struct__pp_user_t = mod->getTypeByName("struct._pp_user_t");
  if (!StructTy_struct__pp_user_t) {
    StructTy_struct__pp_user_t = StructType::create(mod->getContext(), "struct._pp_user_t");
  }
  std::vector<Type*>StructTy_struct__pp_user_t_fields;
  StructTy_struct__pp_user_t_fields.push_back(IntegerType::get(mod->getContext(), 32));
  StructTy_struct__pp_user_t_fields.push_back(IntegerType::get(mod->getContext(), 32));
  StructTy_struct__pp_user_t_fields.push_back(IntegerType::get(mod->getContext(), 32));
  if (StructTy_struct__pp_user_t->isOpaque()) {
    StructTy_struct__pp_user_t->setBody(StructTy_struct__pp_user_t_fields, /*isPacked=*/false);
  }

  PointerType* PointerTy_1 = PointerType::get(StructTy_struct__pp_user_t, 0);

  FuncTy_0_args.push_back(PointerTy_1);
  FunctionType* FuncTy_0 = FunctionType::get(
      /*Result=*/IntegerType::get(mod->getContext(), 64),
      /*Params=*/FuncTy_0_args,
      /*isVarArg=*/false);

  PointerType* PointerTy_2 = PointerType::get(PointerTy_1, 0);

  PointerType* PointerTy_3 = PointerType::get(IntegerType::get(mod->getContext(), 32), 0);

  PointerType* PointerTy_4 = PointerType::get(IntegerType::get(mod->getContext(), 64), 0);

  std::vector<Type*>FuncTy_6_args;
  FunctionType* FuncTy_6 = FunctionType::get(
      /*Result=*/IntegerType::get(mod->getContext(), 32),
      /*Params=*/FuncTy_6_args,
      /*isVarArg=*/false);

  PointerType* PointerTy_5 = PointerType::get(FuncTy_6, 0);

  ArrayType* ArrayTy_8 = ArrayType::get(IntegerType::get(mod->getContext(), 64), 1024);

  PointerType* PointerTy_7 = PointerType::get(ArrayTy_8, 0);

  PointerType* PointerTy_9 = PointerType::get(IntegerType::get(mod->getContext(), 8), 0);

  std::vector<Type*>FuncTy_11_args;
  FuncTy_11_args.push_back(IntegerType::get(mod->getContext(), 64));
  FunctionType* FuncTy_11 = FunctionType::get(
      /*Result=*/IntegerType::get(mod->getContext(), 64),
      /*Params=*/FuncTy_11_args,
      /*isVarArg=*/true);

  PointerType* PointerTy_10 = PointerType::get(FuncTy_11, 0);


  // Function Declarations

  Function* func_getpid = mod->getFunction("getpid");
  if (!func_getpid) {
    func_getpid = Function::Create(
        /*Type=*/FuncTy_6,
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
        /*Type=*/FuncTy_11,
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

  // Global Variable Declarations

//  GlobalVariable* gvar_array_active_pps = new GlobalVariable(/*Module=*/*mod, 
//      /*Type=*/ArrayTy_8,
//      /*isConstant=*/false,
//      /*Linkage=*/GlobalValue::InternalLinkage,
//      /*Initializer=*/0, // has initializer, specified below
//      /*Name=*/"active_pps");
//  gvar_array_active_pps->setAlignment(16);

  // Constant Definitions
  ConstantInt* const_int32_12 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("1"), 10));
  ConstantInt* const_int32_13 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("1023"), 10));
  ConstantInt* const_int64_14 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("-1"), 10));
//  ConstantAggregateZero* const_array_15 = ConstantAggregateZero::get(ArrayTy_8);
  ConstantInt* const_int32_16 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("0"), 10));
  ConstantInt* const_int64_17 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("0"), 10));
  ConstantInt* const_int64_18 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("329"), 10));

  // Global Variable Definitions
  //gvar_array_active_pps->setInitializer(const_array_15);

  Function* func_pp_begin = mod->getFunction("pp_begin");
  if (!func_pp_begin) {
    func_pp_begin = Function::Create(
        /*Type=*/FuncTy_0,
        /*Linkage=*/GlobalValue::ExternalLinkage,
        /*Name=*/"pp_begin", mod); 
    func_pp_begin->setCallingConv(CallingConv::C);
  }
  AttributeSet func_pp_begin_PAL;
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
    func_pp_begin_PAL = AttributeSet::get(mod->getContext(), Attrs);

  }
  func_pp_begin->setAttributes(func_pp_begin_PAL);
  Function::arg_iterator args = func_pp_begin->arg_begin();
  Value* ptr_user_d = args++;
  ptr_user_d->setName("user_d");

  BasicBlock* label_entry = BasicBlock::Create(mod->getContext(), "entry",func_pp_begin,0);
  BasicBlock* label_if_then = BasicBlock::Create(mod->getContext(), "if.then",func_pp_begin,0);
  BasicBlock* label_if_end = BasicBlock::Create(mod->getContext(), "if.end",func_pp_begin,0);

  // Block entry (label_entry)
  AllocaInst* ptr_user_d_addr = new AllocaInst(PointerTy_1, "user_d.addr", label_entry);
  ptr_user_d_addr->setAlignment(8);
  AllocaInst* ptr_pid = new AllocaInst(IntegerType::get(mod->getContext(), 32), "pid", label_entry);
  ptr_pid->setAlignment(4);
  AllocaInst* ptr_pp_id = new AllocaInst(IntegerType::get(mod->getContext(), 64), "pp_id", label_entry);
  ptr_pp_id->setAlignment(8);
  StoreInst* void_19 = new StoreInst(ptr_user_d, ptr_user_d_addr, false, label_entry);
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
  StoreInst* void_21 = new StoreInst(const_int64_14, ptr_pp_id, false, label_entry);
  void_21->setAlignment(8);
  LoadInst* int32_22 = new LoadInst(ptr_pid, "", false, label_entry);
  int32_22->setAlignment(4);
  CastInst* int64_idxprom = new SExtInst(int32_22, IntegerType::get(mod->getContext(), 64), "idxprom", label_entry);
  std::vector<Value*> ptr_arrayidx_indices;
  ptr_arrayidx_indices.push_back(const_int32_16);
  ptr_arrayidx_indices.push_back(int64_idxprom);
  Instruction* ptr_arrayidx = GetElementPtrInst::Create(gvar_array_active_pps, ptr_arrayidx_indices, "arrayidx", label_entry);
  LoadInst* int64_23 = new LoadInst(ptr_arrayidx, "", false, label_entry);
  int64_23->setAlignment(8);
  ICmpInst* int1_cmp = new ICmpInst(*label_entry, ICmpInst::ICMP_EQ, int64_23, const_int64_17, "cmp");
  BranchInst::Create(label_if_then, label_if_end, int1_cmp, label_entry);

  // Block if.then (label_if_then)
  LoadInst* ptr_25 = new LoadInst(ptr_user_d_addr, "", false, label_if_then);
  ptr_25->setAlignment(8);
  CastInst* ptr_26 = new BitCastInst(ptr_25, PointerTy_9, "", label_if_then);
  std::vector<Value*> int64_call1_params;
  int64_call1_params.push_back(const_int64_18);
  int64_call1_params.push_back(ptr_26);
  CallInst* int64_call1 = CallInst::Create(func_syscall, int64_call1_params, "call1", label_if_then);
  int64_call1->setCallingConv(CallingConv::C);
  int64_call1->setTailCall(false);
  AttributeSet int64_call1_PAL;
  {
    SmallVector<AttributeSet, 4> Attrs;
    AttributeSet PAS;
    {
      AttrBuilder B;
      B.addAttribute(Attribute::NoUnwind);
      PAS = AttributeSet::get(mod->getContext(), ~0U, B);
    }

    Attrs.push_back(PAS);
    int64_call1_PAL = AttributeSet::get(mod->getContext(), Attrs);

  }
  int64_call1->setAttributes(int64_call1_PAL);

  StoreInst* void_27 = new StoreInst(int64_call1, ptr_pp_id, false, label_if_then);
  void_27->setAlignment(8);
  LoadInst* int64_28 = new LoadInst(ptr_pp_id, "", false, label_if_then);
  int64_28->setAlignment(8);
  LoadInst* int32_29 = new LoadInst(ptr_pid, "", false, label_if_then);
  int32_29->setAlignment(4);
  CastInst* int64_idxprom2 = new SExtInst(int32_29, IntegerType::get(mod->getContext(), 64), "idxprom2", label_if_then);
  std::vector<Value*> ptr_arrayidx3_indices;
  ptr_arrayidx3_indices.push_back(const_int32_16);
  ptr_arrayidx3_indices.push_back(int64_idxprom2);
  Instruction* ptr_arrayidx3 = GetElementPtrInst::Create(gvar_array_active_pps, ptr_arrayidx3_indices, "arrayidx3", label_if_then);
  StoreInst* void_30 = new StoreInst(int64_28, ptr_arrayidx3, false, label_if_then);
  void_30->setAlignment(8);
  BranchInst::Create(label_if_end, label_if_then);

  // Block if.end (label_if_end)
  LoadInst* int64_32 = new LoadInst(ptr_pp_id, "", false, label_if_end);
  int64_32->setAlignment(8);
  ReturnInst::Create(mod->getContext(), int64_32, label_if_end);
  return func_pp_begin;
}
