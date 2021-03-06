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


Function* define_pp_begin(Module *mod, GlobalVariable* gvar_array_active_pps, GlobalVariable* gvar_array_trust_pp_nos, GlobalVariable* gvar_array_duration_check_pp_nos) {

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
  FuncTy_0_args.push_back(IntegerType::get(mod->getContext(), 32));
  FunctionType* FuncTy_0 = FunctionType::get(
      /*Result=*/IntegerType::get(mod->getContext(), 64),
      /*Params=*/FuncTy_0_args,
      /*isVarArg=*/false);

  PointerType* PointerTy_2 = PointerType::get(PointerTy_1, 0);

  PointerType* PointerTy_3 = PointerType::get(IntegerType::get(mod->getContext(), 32), 0);

  PointerType* PointerTy_4 = PointerType::get(IntegerType::get(mod->getContext(), 64), 0);

  std::vector<Type*>FuncTy_6_args;
  FuncTy_6_args.push_back(IntegerType::get(mod->getContext(), 64));
  FunctionType* FuncTy_6 = FunctionType::get(
      /*Result=*/IntegerType::get(mod->getContext(), 64),
      /*Params=*/FuncTy_6_args,
      /*isVarArg=*/true);

  PointerType* PointerTy_5 = PointerType::get(FuncTy_6, 0);

  ArrayType* ArrayTy_8 = ArrayType::get(IntegerType::get(mod->getContext(), 64), 128);

  PointerType* PointerTy_7 = PointerType::get(ArrayTy_8, 0);

  ArrayType* ArrayTy_10 = ArrayType::get(ArrayTy_8, 1024);

  PointerType* PointerTy_9 = PointerType::get(ArrayTy_10, 0);

  PointerType* PointerTy_11 = PointerType::get(IntegerType::get(mod->getContext(), 8), 0);

  ArrayType* ArrayTy_13 = ArrayType::get(IntegerType::get(mod->getContext(), 8), 57);

  PointerType* PointerTy_12 = PointerType::get(ArrayTy_13, 0);

  std::vector<Type*>FuncTy_15_args;
  FuncTy_15_args.push_back(PointerTy_11);
  FunctionType* FuncTy_15 = FunctionType::get(
      /*Result=*/IntegerType::get(mod->getContext(), 32),
      /*Params=*/FuncTy_15_args,
      /*isVarArg=*/true);

  PointerType* PointerTy_14 = PointerType::get(FuncTy_15, 0);


  // Function Declarations

  Function* func_syscall = mod->getFunction("syscall");
  if (!func_syscall) {
    func_syscall = Function::Create(
        /*Type=*/FuncTy_6,
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

  Function* func_printf = mod->getFunction("printf");
  if (!func_printf) {
    func_printf = Function::Create(
        /*Type=*/FuncTy_15,
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
//      /*Type=*/ArrayTy_10,
//      /*isConstant=*/false,
//      /*Linkage=*/GlobalValue::ExternalLinkage,
//      /*Initializer=*/0, 
//      /*Name=*/"active_pps");

  GlobalVariable* gvar_array__str = new GlobalVariable(/*Module=*/*mod, 
      /*Type=*/ArrayTy_13,
      /*isConstant=*/true,
      /*Linkage=*/GlobalValue::PrivateLinkage,
      /*Initializer=*/0, // has initializer, specified below
      /*Name=*/".str");
  gvar_array__str->setAlignment(1);

  // Constant Definitions
  ConstantInt* const_int32_16 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("1"), 10));
  ConstantInt* const_int64_17 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("186"), 10));
  ConstantInt* const_int64_18 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("1023"), 10));
  ConstantInt* const_int64_19 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("-1"), 10));
  ConstantInt* const_int32_20 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("0"), 10));
  ConstantInt* const_int64_21 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("0"), 10));
  ConstantInt* const_int32_22 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("2"), 10));
  std::vector<Constant*> const_ptr_23_indices;
  const_ptr_23_indices.push_back(const_int32_20);
  const_ptr_23_indices.push_back(const_int32_20);
  Constant* const_ptr_23 = ConstantExpr::getGetElementPtr(gvar_array__str, const_ptr_23_indices);
  Constant *const_array_24 = ConstantDataArray::getString(mod->getContext(), "Beginning progress period %d: wss %d, reuse %d, rsrc %d\x0A", true);

  // Global Variable Definitions
  gvar_array__str->setInitializer(const_array_24);

  Function* func_pp_begin = mod->getFunction("pp_begin");
  if (!func_pp_begin) {
    func_pp_begin = Function::Create(
        /*Type=*/FuncTy_0,
        /*Linkage=*/GlobalValue::InternalLinkage,
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
  Value* int32_pp_no = args++;
  int32_pp_no->setName("pp_no");

  BasicBlock* label_entry = BasicBlock::Create(mod->getContext(), "entry",func_pp_begin,0);
  BasicBlock* label_if_then = BasicBlock::Create(mod->getContext(), "if.then",func_pp_begin,0);
  BasicBlock* label_if_end = BasicBlock::Create(mod->getContext(), "if.end",func_pp_begin,0);

  // Block entry (label_entry)
  AllocaInst* ptr_user_d_addr = new AllocaInst(PointerTy_1, "user_d.addr", label_entry);
  ptr_user_d_addr->setAlignment(8);
  AllocaInst* ptr_pp_no_addr = new AllocaInst(IntegerType::get(mod->getContext(), 32), "pp_no.addr", label_entry);
  ptr_pp_no_addr->setAlignment(4);
  AllocaInst* ptr_tid = new AllocaInst(IntegerType::get(mod->getContext(), 32), "tid", label_entry);
  ptr_tid->setAlignment(4);
  AllocaInst* ptr_pp_id = new AllocaInst(IntegerType::get(mod->getContext(), 64), "pp_id", label_entry);
  ptr_pp_id->setAlignment(8);
  StoreInst* void_25 = new StoreInst(ptr_user_d, ptr_user_d_addr, false, label_entry);
  void_25->setAlignment(8);
  StoreInst* void_26 = new StoreInst(int32_pp_no, ptr_pp_no_addr, false, label_entry);
  void_26->setAlignment(4);
  CallInst* int64_call = CallInst::Create(func_syscall, const_int64_17, "call", label_entry);
  int64_call->setCallingConv(CallingConv::C);
  int64_call->setTailCall(false);
  AttributeSet int64_call_PAL;
  {
    SmallVector<AttributeSet, 4> Attrs;
    AttributeSet PAS;
    {
      AttrBuilder B;
      B.addAttribute(Attribute::NoUnwind);
      PAS = AttributeSet::get(mod->getContext(), ~0U, B);
    }

    Attrs.push_back(PAS);
    int64_call_PAL = AttributeSet::get(mod->getContext(), Attrs);

  }
  int64_call->setAttributes(int64_call_PAL);

  BinaryOperator* int64_and = BinaryOperator::Create(Instruction::And, int64_call, const_int64_18, "and", label_entry);
  CastInst* int32_conv = new TruncInst(int64_and, IntegerType::get(mod->getContext(), 32), "conv", label_entry);
  StoreInst* void_27 = new StoreInst(int32_conv, ptr_tid, false, label_entry);
  void_27->setAlignment(4);
  StoreInst* void_28 = new StoreInst(const_int64_19, ptr_pp_id, false, label_entry);
  void_28->setAlignment(8);
  LoadInst* int32_29 = new LoadInst(ptr_pp_no_addr, "", false, label_entry);
  int32_29->setAlignment(4);
  CastInst* int64_idxprom = new SExtInst(int32_29, IntegerType::get(mod->getContext(), 64), "idxprom", label_entry);
  LoadInst* int32_30 = new LoadInst(ptr_tid, "", false, label_entry);
  int32_30->setAlignment(4);
  CastInst* int64_idxprom1 = new SExtInst(int32_30, IntegerType::get(mod->getContext(), 64), "idxprom1", label_entry);
  std::vector<Value*> ptr_arrayidx_indices;
  ptr_arrayidx_indices.push_back(const_int32_20);
  ptr_arrayidx_indices.push_back(int64_idxprom1);
  Instruction* ptr_arrayidx = GetElementPtrInst::Create(gvar_array_active_pps, ptr_arrayidx_indices, "arrayidx", label_entry);
  std::vector<Value*> ptr_arrayidx2_indices;
  ptr_arrayidx2_indices.push_back(const_int32_20);
  ptr_arrayidx2_indices.push_back(int64_idxprom);
  Instruction* ptr_arrayidx2 = GetElementPtrInst::Create(ptr_arrayidx, ptr_arrayidx2_indices, "arrayidx2", label_entry);
  LoadInst* int64_31 = new LoadInst(ptr_arrayidx2, "", false, label_entry);
  int64_31->setAlignment(8);
  ICmpInst* int1_cmp = new ICmpInst(*label_entry, ICmpInst::ICMP_EQ, int64_31, const_int64_21, "cmp");
  BranchInst::Create(label_if_then, label_if_end, int1_cmp, label_entry);

  // Block if.then (label_if_then)
  LoadInst* int32_33 = new LoadInst(ptr_tid, "", false, label_if_then);
  int32_33->setAlignment(4);
  LoadInst* int32_34 = new LoadInst(ptr_pp_no_addr, "", false, label_if_then);
  int32_34->setAlignment(4);
  BinaryOperator* int32_add = BinaryOperator::Create(Instruction::Add, int32_33, int32_34, "add", label_if_then);
  CastInst* int64_conv4 = new SExtInst(int32_add, IntegerType::get(mod->getContext(), 64), "conv4", label_if_then);
  StoreInst* void_35 = new StoreInst(int64_conv4, ptr_pp_id, false, label_if_then);
  void_35->setAlignment(8);
  LoadInst* int64_36 = new LoadInst(ptr_pp_id, "", false, label_if_then);
  int64_36->setAlignment(8);
  LoadInst* int32_37 = new LoadInst(ptr_pp_no_addr, "", false, label_if_then);
  int32_37->setAlignment(4);
  CastInst* int64_idxprom5 = new SExtInst(int32_37, IntegerType::get(mod->getContext(), 64), "idxprom5", label_if_then);
  LoadInst* int32_38 = new LoadInst(ptr_tid, "", false, label_if_then);
  int32_38->setAlignment(4);
  CastInst* int64_idxprom6 = new SExtInst(int32_38, IntegerType::get(mod->getContext(), 64), "idxprom6", label_if_then);
  std::vector<Value*> ptr_arrayidx7_indices;
  ptr_arrayidx7_indices.push_back(const_int32_20);
  ptr_arrayidx7_indices.push_back(int64_idxprom6);
  Instruction* ptr_arrayidx7 = GetElementPtrInst::Create(gvar_array_active_pps, ptr_arrayidx7_indices, "arrayidx7", label_if_then);
  std::vector<Value*> ptr_arrayidx8_indices;
  ptr_arrayidx8_indices.push_back(const_int32_20);
  ptr_arrayidx8_indices.push_back(int64_idxprom5);
  Instruction* ptr_arrayidx8 = GetElementPtrInst::Create(ptr_arrayidx7, ptr_arrayidx8_indices, "arrayidx8", label_if_then);
  StoreInst* void_39 = new StoreInst(int64_36, ptr_arrayidx8, false, label_if_then);
  void_39->setAlignment(8);
  LoadInst* int32_40 = new LoadInst(ptr_pp_no_addr, "", false, label_if_then);
  int32_40->setAlignment(4);
  LoadInst* ptr_41 = new LoadInst(ptr_user_d_addr, "", false, label_if_then);
  ptr_41->setAlignment(8);
  std::vector<Value*> ptr_wss_indices;
  ptr_wss_indices.push_back(const_int32_20);
  ptr_wss_indices.push_back(const_int32_20);
  Instruction* ptr_wss = GetElementPtrInst::Create(ptr_41, ptr_wss_indices, "wss", label_if_then);
  LoadInst* int32_42 = new LoadInst(ptr_wss, "", false, label_if_then);
  int32_42->setAlignment(4);
  LoadInst* ptr_43 = new LoadInst(ptr_user_d_addr, "", false, label_if_then);
  ptr_43->setAlignment(8);
  std::vector<Value*> ptr_reuse_indices;
  ptr_reuse_indices.push_back(const_int32_20);
  ptr_reuse_indices.push_back(const_int32_16);
  Instruction* ptr_reuse = GetElementPtrInst::Create(ptr_43, ptr_reuse_indices, "reuse", label_if_then);
  LoadInst* int32_44 = new LoadInst(ptr_reuse, "", false, label_if_then);
  int32_44->setAlignment(4);
  LoadInst* ptr_45 = new LoadInst(ptr_user_d_addr, "", false, label_if_then);
  ptr_45->setAlignment(8);
  std::vector<Value*> ptr_resource_indices;
  ptr_resource_indices.push_back(const_int32_20);
  ptr_resource_indices.push_back(const_int32_22);
  Instruction* ptr_resource = GetElementPtrInst::Create(ptr_45, ptr_resource_indices, "resource", label_if_then);
  LoadInst* int32_46 = new LoadInst(ptr_resource, "", false, label_if_then);
  int32_46->setAlignment(4);
  std::vector<Value*> int32_call9_params;
  int32_call9_params.push_back(const_ptr_23);
  int32_call9_params.push_back(int32_40);
  int32_call9_params.push_back(int32_42);
  int32_call9_params.push_back(int32_44);
  int32_call9_params.push_back(int32_46);
  CallInst* int32_call9 = CallInst::Create(func_printf, int32_call9_params, "call9", label_if_then);
  int32_call9->setCallingConv(CallingConv::C);
  int32_call9->setTailCall(false);
  AttributeSet int32_call9_PAL;
  int32_call9->setAttributes(int32_call9_PAL);

  BranchInst::Create(label_if_end, label_if_then);

  // Block if.end (label_if_end)
  LoadInst* int64_48 = new LoadInst(ptr_pp_id, "", false, label_if_end);
  int64_48->setAlignment(8);
  ReturnInst::Create(mod->getContext(), int64_48, label_if_end);
  return func_pp_begin;
}
