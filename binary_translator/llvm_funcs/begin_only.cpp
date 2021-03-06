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

  ArrayType* ArrayTy_11 = ArrayType::get(IntegerType::get(mod->getContext(), 8), 58);

  PointerType* PointerTy_10 = PointerType::get(ArrayTy_11, 0);

  std::vector<Type*>FuncTy_13_args;
  FuncTy_13_args.push_back(PointerTy_9);
  FunctionType* FuncTy_13 = FunctionType::get(
      /*Result=*/IntegerType::get(mod->getContext(), 32),
      /*Params=*/FuncTy_13_args,
      /*isVarArg=*/true);

  PointerType* PointerTy_12 = PointerType::get(FuncTy_13, 0);


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

  Function* func_printf = mod->getFunction("printf");
  if (!func_printf) {
    func_printf = Function::Create(
        /*Type=*/FuncTy_13,
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
//      /*Type=*/ArrayTy_8,
//      /*isConstant=*/false,
//      /*Linkage=*/GlobalValue::InternalLinkage,
//      /*Initializer=*/0, // has initializer, specified below
//      /*Name=*/"active_pps");
//  gvar_array_active_pps->setAlignment(16);

  GlobalVariable* gvar_int64_pp_ctr = new GlobalVariable(/*Module=*/*mod, 
      /*Type=*/IntegerType::get(mod->getContext(), 64),
      /*isConstant=*/false,
      /*Linkage=*/GlobalValue::InternalLinkage,
      /*Initializer=*/0, // has initializer, specified below
      /*Name=*/"pp_ctr");
  gvar_int64_pp_ctr->setAlignment(8);

  GlobalVariable* gvar_array__str = new GlobalVariable(/*Module=*/*mod, 
      /*Type=*/ArrayTy_11,
      /*isConstant=*/true,
      /*Linkage=*/GlobalValue::PrivateLinkage,
      /*Initializer=*/0, // has initializer, specified below
      /*Name=*/".str");
  gvar_array__str->setAlignment(1);

  // Constant Definitions
  ConstantInt* const_int32_14 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("1"), 10));
  ConstantInt* const_int32_15 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("1023"), 10));
  ConstantInt* const_int64_16 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("-1"), 10));
  //ConstantAggregateZero* const_array_17 = ConstantAggregateZero::get(ArrayTy_8);
  ConstantInt* const_int32_18 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("0"), 10));
  ConstantInt* const_int64_19 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("0"), 10));
  ConstantInt* const_int64_20 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("1"), 10));
  ConstantInt* const_int32_21 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("2"), 10));
  std::vector<Constant*> const_ptr_22_indices;
  const_ptr_22_indices.push_back(const_int32_18);
  const_ptr_22_indices.push_back(const_int32_18);
  Constant* const_ptr_22 = ConstantExpr::getGetElementPtr(gvar_array__str, const_ptr_22_indices);
  Constant *const_array_23 = ConstantDataArray::getString(mod->getContext(), "Beginning progress period %ld: wss %d, reuse %d, rsrc %d\x0A", true);

  // Global Variable Definitions
  //gvar_array_active_pps->setInitializer(const_array_17);
  gvar_int64_pp_ctr->setInitializer(const_int64_19);
  gvar_array__str->setInitializer(const_array_23);

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
  AllocaInst* ptr_my_ctr = new AllocaInst(IntegerType::get(mod->getContext(), 64), "my_ctr", label_entry);
  ptr_my_ctr->setAlignment(8);
  StoreInst* void_24 = new StoreInst(ptr_user_d, ptr_user_d_addr, false, label_entry);
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

  BinaryOperator* int32_and = BinaryOperator::Create(Instruction::And, int32_call, const_int32_15, "and", label_entry);
  StoreInst* void_25 = new StoreInst(int32_and, ptr_pid, false, label_entry);
  void_25->setAlignment(4);
  StoreInst* void_26 = new StoreInst(const_int64_16, ptr_pp_id, false, label_entry);
  void_26->setAlignment(8);
  LoadInst* int32_27 = new LoadInst(ptr_pid, "", false, label_entry);
  int32_27->setAlignment(4);
  CastInst* int64_idxprom = new SExtInst(int32_27, IntegerType::get(mod->getContext(), 64), "idxprom", label_entry);
  std::vector<Value*> ptr_arrayidx_indices;
  ptr_arrayidx_indices.push_back(const_int32_18);
  ptr_arrayidx_indices.push_back(int64_idxprom);
  Instruction* ptr_arrayidx = GetElementPtrInst::Create(gvar_array_active_pps, ptr_arrayidx_indices, "arrayidx", label_entry);
  LoadInst* int64_28 = new LoadInst(ptr_arrayidx, "", false, label_entry);
  int64_28->setAlignment(8);
  ICmpInst* int1_cmp = new ICmpInst(*label_entry, ICmpInst::ICMP_EQ, int64_28, const_int64_19, "cmp");
  BranchInst::Create(label_if_then, label_if_end, int1_cmp, label_entry);

  // Block if.then (label_if_then)
  LoadInst* int64_30 = new LoadInst(gvar_int64_pp_ctr, "", false, label_if_then);
  int64_30->setAlignment(8);
  BinaryOperator* int64_inc = BinaryOperator::Create(Instruction::Add, int64_30, const_int64_20, "inc", label_if_then);
  StoreInst* void_31 = new StoreInst(int64_inc, gvar_int64_pp_ctr, false, label_if_then);
  void_31->setAlignment(8);
  StoreInst* void_32 = new StoreInst(int64_inc, ptr_my_ctr, false, label_if_then);
  void_32->setAlignment(8);
  LoadInst* int64_33 = new LoadInst(ptr_my_ctr, "", false, label_if_then);
  int64_33->setAlignment(8);
  LoadInst* int32_34 = new LoadInst(ptr_pid, "", false, label_if_then);
  int32_34->setAlignment(4);
  CastInst* int64_idxprom1 = new SExtInst(int32_34, IntegerType::get(mod->getContext(), 64), "idxprom1", label_if_then);
  std::vector<Value*> ptr_arrayidx2_indices;
  ptr_arrayidx2_indices.push_back(const_int32_18);
  ptr_arrayidx2_indices.push_back(int64_idxprom1);
  Instruction* ptr_arrayidx2 = GetElementPtrInst::Create(gvar_array_active_pps, ptr_arrayidx2_indices, "arrayidx2", label_if_then);
  StoreInst* void_35 = new StoreInst(int64_33, ptr_arrayidx2, false, label_if_then);
  void_35->setAlignment(8);
  LoadInst* int64_36 = new LoadInst(ptr_my_ctr, "", false, label_if_then);
  int64_36->setAlignment(8);
  LoadInst* ptr_37 = new LoadInst(ptr_user_d_addr, "", false, label_if_then);
  ptr_37->setAlignment(8);
  std::vector<Value*> ptr_wss_indices;
  ptr_wss_indices.push_back(const_int32_18);
  ptr_wss_indices.push_back(const_int32_18);
  Instruction* ptr_wss = GetElementPtrInst::Create(ptr_37, ptr_wss_indices, "wss", label_if_then);
  LoadInst* int32_38 = new LoadInst(ptr_wss, "", false, label_if_then);
  int32_38->setAlignment(4);
  LoadInst* ptr_39 = new LoadInst(ptr_user_d_addr, "", false, label_if_then);
  ptr_39->setAlignment(8);
  std::vector<Value*> ptr_reuse_indices;
  ptr_reuse_indices.push_back(const_int32_18);
  ptr_reuse_indices.push_back(const_int32_14);
  Instruction* ptr_reuse = GetElementPtrInst::Create(ptr_39, ptr_reuse_indices, "reuse", label_if_then);
  LoadInst* int32_40 = new LoadInst(ptr_reuse, "", false, label_if_then);
  int32_40->setAlignment(4);
  LoadInst* ptr_41 = new LoadInst(ptr_user_d_addr, "", false, label_if_then);
  ptr_41->setAlignment(8);
  std::vector<Value*> ptr_resource_indices;
  ptr_resource_indices.push_back(const_int32_18);
  ptr_resource_indices.push_back(const_int32_21);
  Instruction* ptr_resource = GetElementPtrInst::Create(ptr_41, ptr_resource_indices, "resource", label_if_then);
  LoadInst* int32_42 = new LoadInst(ptr_resource, "", false, label_if_then);
  int32_42->setAlignment(4);
  std::vector<Value*> int32_call3_params;
  int32_call3_params.push_back(const_ptr_22);
  int32_call3_params.push_back(int64_36);
  int32_call3_params.push_back(int32_38);
  int32_call3_params.push_back(int32_40);
  int32_call3_params.push_back(int32_42);
  CallInst* int32_call3 = CallInst::Create(func_printf, int32_call3_params, "call3", label_if_then);
  int32_call3->setCallingConv(CallingConv::C);
  int32_call3->setTailCall(false);
  AttributeSet int32_call3_PAL;
  int32_call3->setAttributes(int32_call3_PAL);

  LoadInst* int64_43 = new LoadInst(ptr_my_ctr, "", false, label_if_then);
  int64_43->setAlignment(8);
  StoreInst* void_44 = new StoreInst(int64_43, ptr_pp_id, false, label_if_then);
  void_44->setAlignment(8);
  BranchInst::Create(label_if_end, label_if_then);

  // Block if.end (label_if_end)
  LoadInst* int64_46 = new LoadInst(ptr_pp_id, "", false, label_if_end);
  int64_46->setAlignment(8);
  ReturnInst::Create(mod->getContext(), int64_46, label_if_end);
  return func_pp_begin;
}
