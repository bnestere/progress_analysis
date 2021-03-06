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
using namespace std;

Function* define_pp_begin(Module *mod) {

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

  PointerType* PointerTy_3 = PointerType::get(IntegerType::get(mod->getContext(), 64), 0);

  PointerType* PointerTy_4 = PointerType::get(IntegerType::get(mod->getContext(), 32), 0);

  PointerType* PointerTy_5 = PointerType::get(IntegerType::get(mod->getContext(), 8), 0);

  ArrayType* ArrayTy_7 = ArrayType::get(IntegerType::get(mod->getContext(), 8), 58);

  PointerType* PointerTy_6 = PointerType::get(ArrayTy_7, 0);

  std::vector<Type*>FuncTy_9_args;
  FuncTy_9_args.push_back(PointerTy_5);
  FunctionType* FuncTy_9 = FunctionType::get(
      /*Result=*/IntegerType::get(mod->getContext(), 32),
      /*Params=*/FuncTy_9_args,
      /*isVarArg=*/true);

  PointerType* PointerTy_8 = PointerType::get(FuncTy_9, 0);


  // Function Declarations

  Function* func_printf = mod->getFunction("printf");
  if (!func_printf) {
    func_printf = Function::Create(
        /*Type=*/FuncTy_9,
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

  GlobalVariable* gvar_int64_pp_ctr = new GlobalVariable(/*Module=*/*mod, 
      /*Type=*/IntegerType::get(mod->getContext(), 64),
      /*isConstant=*/false,
      /*Linkage=*/GlobalValue::InternalLinkage,
      /*Initializer=*/0, // has initializer, specified below
      /*Name=*/"pp_ctr");
  gvar_int64_pp_ctr->setAlignment(8);

  GlobalVariable* gvar_array__str = new GlobalVariable(/*Module=*/*mod, 
      /*Type=*/ArrayTy_7,
      /*isConstant=*/true,
      /*Linkage=*/GlobalValue::PrivateLinkage,
      /*Initializer=*/0, // has initializer, specified below
      /*Name=*/".str");
  gvar_array__str->setAlignment(1);

  // Constant Definitions
  ConstantInt* const_int32_10 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("1"), 10));
  ConstantInt* const_int64_11 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("0"), 10));
  ConstantInt* const_int64_12 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("1"), 10));
  ConstantInt* const_int32_13 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("0"), 10));
  ConstantInt* const_int32_14 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("2"), 10));
  std::vector<Constant*> const_ptr_15_indices;
  const_ptr_15_indices.push_back(const_int32_13);
  const_ptr_15_indices.push_back(const_int32_13);
  Constant* const_ptr_15 = ConstantExpr::getGetElementPtr(gvar_array__str, const_ptr_15_indices);
  Constant *const_array_16 = ConstantDataArray::getString(mod->getContext(), "Beginning progress period %ld: wss %d, reuse %d, rsrc %d\x0A", true);

  // Global Variable Definitions
  gvar_int64_pp_ctr->setInitializer(const_int64_11);
  gvar_array__str->setInitializer(const_array_16);

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

  // Block entry (label_entry)
  AllocaInst* ptr_user_d_addr = new AllocaInst(PointerTy_1, "user_d.addr", label_entry);
  ptr_user_d_addr->setAlignment(8);
  AllocaInst* ptr_my_ctr = new AllocaInst(IntegerType::get(mod->getContext(), 64), "my_ctr", label_entry);
  ptr_my_ctr->setAlignment(8);
  StoreInst* void_17 = new StoreInst(ptr_user_d, ptr_user_d_addr, false, label_entry);
  void_17->setAlignment(8);
  LoadInst* int64_18 = new LoadInst(gvar_int64_pp_ctr, "", false, label_entry);
  int64_18->setAlignment(8);
  BinaryOperator* int64_inc = BinaryOperator::Create(Instruction::Add, int64_18, const_int64_12, "inc", label_entry);
  StoreInst* void_19 = new StoreInst(int64_inc, gvar_int64_pp_ctr, false, label_entry);
  void_19->setAlignment(8);
  StoreInst* void_20 = new StoreInst(int64_18, ptr_my_ctr, false, label_entry);
  void_20->setAlignment(8);
  LoadInst* int64_21 = new LoadInst(ptr_my_ctr, "", false, label_entry);
  int64_21->setAlignment(8);
  LoadInst* ptr_22 = new LoadInst(ptr_user_d_addr, "", false, label_entry);
  ptr_22->setAlignment(8);
  std::vector<Value*> ptr_wss_indices;
  ptr_wss_indices.push_back(const_int32_13);
  ptr_wss_indices.push_back(const_int32_13);
  Instruction* ptr_wss = GetElementPtrInst::Create(ptr_22, ptr_wss_indices, "wss", label_entry);
  LoadInst* int32_23 = new LoadInst(ptr_wss, "", false, label_entry);
  int32_23->setAlignment(4);
  LoadInst* ptr_24 = new LoadInst(ptr_user_d_addr, "", false, label_entry);
  ptr_24->setAlignment(8);
  std::vector<Value*> ptr_reuse_indices;
  ptr_reuse_indices.push_back(const_int32_13);
  ptr_reuse_indices.push_back(const_int32_10);
  Instruction* ptr_reuse = GetElementPtrInst::Create(ptr_24, ptr_reuse_indices, "reuse", label_entry);
  LoadInst* int32_25 = new LoadInst(ptr_reuse, "", false, label_entry);
  int32_25->setAlignment(4);
  LoadInst* ptr_26 = new LoadInst(ptr_user_d_addr, "", false, label_entry);
  ptr_26->setAlignment(8);
  std::vector<Value*> ptr_resource_indices;
  ptr_resource_indices.push_back(const_int32_13);
  ptr_resource_indices.push_back(const_int32_14);
  Instruction* ptr_resource = GetElementPtrInst::Create(ptr_26, ptr_resource_indices, "resource", label_entry);
  LoadInst* int32_27 = new LoadInst(ptr_resource, "", false, label_entry);
  int32_27->setAlignment(4);
  std::vector<Value*> int32_call_params;
  int32_call_params.push_back(const_ptr_15);
  int32_call_params.push_back(int64_21);
  int32_call_params.push_back(int32_23);
  int32_call_params.push_back(int32_25);
  int32_call_params.push_back(int32_27);
  CallInst* int32_call = CallInst::Create(func_printf, int32_call_params, "call", label_entry);
  int32_call->setCallingConv(CallingConv::C);
  int32_call->setTailCall(false);
  AttributeSet int32_call_PAL;
  int32_call->setAttributes(int32_call_PAL);

  LoadInst* int64_28 = new LoadInst(ptr_my_ctr, "", false, label_entry);
  int64_28->setAlignment(8);
  ReturnInst::Create(mod->getContext(), int64_28, label_entry);
  return func_pp_begin;
}
