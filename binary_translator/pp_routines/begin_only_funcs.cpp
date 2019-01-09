// Generated by llvm2cpp - DO NOT MODIFY!


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

PointerType* PointerTy_2 = PointerType::get(IntegerType::get(mod->getContext(), 64), 0);

PointerType* PointerTy_3 = PointerType::get(PointerTy_1, 0);

PointerType* PointerTy_4 = PointerType::get(IntegerType::get(mod->getContext(), 32), 0);

PointerType* PointerTy_5 = PointerType::get(IntegerType::get(mod->getContext(), 8), 0);

ArrayType* ArrayTy_7 = ArrayType::get(IntegerType::get(mod->getContext(), 8), 54);

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

GlobalVariable* gvar_array__str = new GlobalVariable(/*Module=*/*mod, 
/*Type=*/ArrayTy_7,
/*isConstant=*/true,
/*Linkage=*/GlobalValue::PrivateLinkage,
/*Initializer=*/0, // has initializer, specified below
/*Name=*/".str");
gvar_array__str->setAlignment(1);

// Constant Definitions
ConstantInt* const_int32_10 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("1"), 10));
ConstantInt* const_int32_11 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("0"), 10));
ConstantInt* const_int32_12 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("2"), 10));
std::vector<Constant*> const_ptr_13_indices;
const_ptr_13_indices.push_back(const_int32_11);
const_ptr_13_indices.push_back(const_int32_11);
Constant* const_ptr_13 = ConstantExpr::getGetElementPtr(gvar_array__str, const_ptr_13_indices);
Constant *const_array_14 = ConstantDataArray::getString(mod->getContext(), "Beginning progress period: wss %d, reuse %d, rsrc %d\x0A", true);

// Global Variable Definitions
gvar_array__str->setInitializer(const_array_14);

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

BasicBlock* label_entry = BasicBlock::Create(mod->getContext(), "entry",func_pp_begin,0);

// Block entry (label_entry)
AllocaInst* ptr_retval = new AllocaInst(IntegerType::get(mod->getContext(), 64), "retval", label_entry);
ptr_retval->setAlignment(8);
AllocaInst* ptr_user_d_addr = new AllocaInst(PointerTy_1, "user_d.addr", label_entry);
ptr_user_d_addr->setAlignment(8);
StoreInst* void_15 = new StoreInst(ptr_user_d, ptr_user_d_addr, false, label_entry);
void_15->setAlignment(8);
LoadInst* ptr_16 = new LoadInst(ptr_user_d_addr, "", false, label_entry);
ptr_16->setAlignment(8);
std::vector<Value*> ptr_wss_indices;
ptr_wss_indices.push_back(const_int32_11);
ptr_wss_indices.push_back(const_int32_11);
Instruction* ptr_wss = GetElementPtrInst::Create(ptr_16, ptr_wss_indices, "wss", label_entry);
LoadInst* int32_17 = new LoadInst(ptr_wss, "", false, label_entry);
int32_17->setAlignment(4);
LoadInst* ptr_18 = new LoadInst(ptr_user_d_addr, "", false, label_entry);
ptr_18->setAlignment(8);
std::vector<Value*> ptr_reuse_indices;
ptr_reuse_indices.push_back(const_int32_11);
ptr_reuse_indices.push_back(const_int32_10);
Instruction* ptr_reuse = GetElementPtrInst::Create(ptr_18, ptr_reuse_indices, "reuse", label_entry);
LoadInst* int32_19 = new LoadInst(ptr_reuse, "", false, label_entry);
int32_19->setAlignment(4);
LoadInst* ptr_20 = new LoadInst(ptr_user_d_addr, "", false, label_entry);
ptr_20->setAlignment(8);
std::vector<Value*> ptr_resource_indices;
ptr_resource_indices.push_back(const_int32_11);
ptr_resource_indices.push_back(const_int32_12);
Instruction* ptr_resource = GetElementPtrInst::Create(ptr_20, ptr_resource_indices, "resource", label_entry);
LoadInst* int32_21 = new LoadInst(ptr_resource, "", false, label_entry);
int32_21->setAlignment(4);
std::vector<Value*> int32_call_params;
int32_call_params.push_back(const_ptr_13);
int32_call_params.push_back(int32_17);
int32_call_params.push_back(int32_19);
int32_call_params.push_back(int32_21);
CallInst* int32_call = CallInst::Create(func_printf, int32_call_params, "call", label_entry);
int32_call->setCallingConv(CallingConv::C);
int32_call->setTailCall(false);
AttributeSet int32_call_PAL;
int32_call->setAttributes(int32_call_PAL);

LoadInst* int64_22 = new LoadInst(ptr_retval, "", false, label_entry);
ReturnInst::Create(mod->getContext(), int64_22, label_entry);
return func_pp_begin;
}

Function* define_call_begg(Module *mod) {

// Type Definitions
std::vector<Type*>FuncTy_24_args;
FunctionType* FuncTy_24 = FunctionType::get(
 /*Result=*/Type::getVoidTy(mod->getContext()),
 /*Params=*/FuncTy_24_args,
 /*isVarArg=*/false);

PointerType* PointerTy_25 = PointerType::get(FuncTy_0, 0);


// Function Declarations

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

// Global Variable Declarations

// Constant Definitions

// Global Variable Definitions

Function* func_call_begg = mod->getFunction("call_begg");
if (!func_call_begg) {
func_call_begg = Function::Create(
 /*Type=*/FuncTy_24,
 /*Linkage=*/GlobalValue::InternalLinkage,
 /*Name=*/"call_begg", mod); 
func_call_begg->setCallingConv(CallingConv::C);
}
AttributeSet func_call_begg_PAL;
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
 func_call_begg_PAL = AttributeSet::get(mod->getContext(), Attrs);
 
}
func_call_begg->setAttributes(func_call_begg_PAL);

BasicBlock* label_entry_26 = BasicBlock::Create(mod->getContext(), "entry",func_call_begg,0);

// Block entry (label_entry_26)
AllocaInst* ptr_user_t = new AllocaInst(StructTy_struct__pp_user_t, "user_t", label_entry_26);
ptr_user_t->setAlignment(4);
std::vector<Value*> ptr_wss_27_indices;
ptr_wss_27_indices.push_back(const_int32_11);
ptr_wss_27_indices.push_back(const_int32_11);
Instruction* ptr_wss_27 = GetElementPtrInst::Create(ptr_user_t, ptr_wss_27_indices, "wss", label_entry_26);
StoreInst* void_28 = new StoreInst(const_int32_12, ptr_wss_27, false, label_entry_26);
void_28->setAlignment(4);
std::vector<Value*> ptr_reuse_29_indices;
ptr_reuse_29_indices.push_back(const_int32_11);
ptr_reuse_29_indices.push_back(const_int32_10);
Instruction* ptr_reuse_29 = GetElementPtrInst::Create(ptr_user_t, ptr_reuse_29_indices, "reuse", label_entry_26);
StoreInst* void_30 = new StoreInst(const_int32_10, ptr_reuse_29, false, label_entry_26);
void_30->setAlignment(4);
std::vector<Value*> ptr_resource_31_indices;
ptr_resource_31_indices.push_back(const_int32_11);
ptr_resource_31_indices.push_back(const_int32_12);
Instruction* ptr_resource_31 = GetElementPtrInst::Create(ptr_user_t, ptr_resource_31_indices, "resource", label_entry_26);
StoreInst* void_32 = new StoreInst(const_int32_11, ptr_resource_31, false, label_entry_26);
void_32->setAlignment(4);
CallInst* int64_call = CallInst::Create(func_pp_begin, ptr_user_t, "call", label_entry_26);
int64_call->setCallingConv(CallingConv::C);
int64_call->setTailCall(false);
AttributeSet int64_call_PAL;
int64_call->setAttributes(int64_call_PAL);

ReturnInst::Create(mod->getContext(), label_entry_26);
return func_call_begg;
}

Function* define_main(Module *mod) {

// Type Definitions
std::vector<Type*>FuncTy_34_args;
FuncTy_34_args.push_back(IntegerType::get(mod->getContext(), 32));
PointerType* PointerTy_35 = PointerType::get(PointerTy_5, 0);

FuncTy_34_args.push_back(PointerTy_35);
FunctionType* FuncTy_34 = FunctionType::get(
 /*Result=*/IntegerType::get(mod->getContext(), 32),
 /*Params=*/FuncTy_34_args,
 /*isVarArg=*/false);

PointerType* PointerTy_36 = PointerType::get(PointerTy_35, 0);

PointerType* PointerTy_37 = PointerType::get(FuncTy_24, 0);


// Function Declarations

Function* func_call_begg = mod->getFunction("call_begg");
if (!func_call_begg) {
func_call_begg = Function::Create(
 /*Type=*/FuncTy_24,
 /*Linkage=*/GlobalValue::InternalLinkage,
 /*Name=*/"call_begg", mod); 
func_call_begg->setCallingConv(CallingConv::C);
}
AttributeSet func_call_begg_PAL;
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
 func_call_begg_PAL = AttributeSet::get(mod->getContext(), Attrs);
 
}
func_call_begg->setAttributes(func_call_begg_PAL);

// Global Variable Declarations

// Constant Definitions

// Global Variable Definitions

Function* func_main = mod->getFunction("main");
if (!func_main) {
func_main = Function::Create(
 /*Type=*/FuncTy_34,
 /*Linkage=*/GlobalValue::ExternalLinkage,
 /*Name=*/"main", mod); 
func_main->setCallingConv(CallingConv::C);
}
AttributeSet func_main_PAL;
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
 func_main_PAL = AttributeSet::get(mod->getContext(), Attrs);
 
}
func_main->setAttributes(func_main_PAL);
Function::arg_iterator args = func_main->arg_begin();
Value* int32_argc = args++;
int32_argc->setName("argc");
Value* ptr_argv = args++;
ptr_argv->setName("argv");

BasicBlock* label_entry_38 = BasicBlock::Create(mod->getContext(), "entry",func_main,0);

// Block entry (label_entry_38)
AllocaInst* ptr_retval_39 = new AllocaInst(IntegerType::get(mod->getContext(), 32), "retval", label_entry_38);
ptr_retval_39->setAlignment(4);
AllocaInst* ptr_argc_addr = new AllocaInst(IntegerType::get(mod->getContext(), 32), "argc.addr", label_entry_38);
ptr_argc_addr->setAlignment(4);
AllocaInst* ptr_argv_addr = new AllocaInst(PointerTy_35, "argv.addr", label_entry_38);
ptr_argv_addr->setAlignment(8);
StoreInst* void_40 = new StoreInst(const_int32_11, ptr_retval_39, false, label_entry_38);
StoreInst* void_41 = new StoreInst(int32_argc, ptr_argc_addr, false, label_entry_38);
void_41->setAlignment(4);
StoreInst* void_42 = new StoreInst(ptr_argv, ptr_argv_addr, false, label_entry_38);
void_42->setAlignment(8);
CallInst* void_43 = CallInst::Create(func_call_begg, "", label_entry_38);
void_43->setCallingConv(CallingConv::C);
void_43->setTailCall(false);
AttributeSet void_43_PAL;
void_43->setAttributes(void_43_PAL);

ReturnInst::Create(mod->getContext(), const_int32_11, label_entry_38);
return func_main;
}
