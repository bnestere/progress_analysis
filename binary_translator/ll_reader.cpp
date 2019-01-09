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
#include "llvm/IR/Instruction.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/CFG.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/IR/Dominators.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/PostDominators.h"
#include "llvm/Transforms/Utils/LoopUtils.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/ErrorOr.h"
#include "llvm/Bitcode/ReaderWriter.h" 

#include <set>
#include <map>

//#include "pp_funcs.h"

#include <iostream>

#include "pp_reader.h"
#include "pp_funcs.h"

using namespace llvm;
using namespace std;

typedef struct _pp_loop_t {
  pp_set_t *pp;
  Loop *loop;
} pp_loop_t;

static LLVMContext MyGlobalContext;

//Function* define_pp_begin(Module *mod);
//Function* define_pp_end(Module *mod);
//Function* define_call_begg(Module *mod, const char*);
CallInst* create_pp_begin_call(Module *mod, const char *wssVal, ConstantInt*, IRBuilder<> *builder);
//CallInst* create_pp_begin_call(Module *mod, const char *wssVal, BasicBlock *bb);

Function *func_pp_begin;
Function *func_pp_end;

void find_common_dominators(set<pp_set_t*> *pps_to_set, map<int, vector<pp_set_t*>*> *pp_no_map) {

  for(auto ppi = pps_to_set->begin(); ppi != pps_to_set->end(); ++ppi) {
    pp_set_t *pp = *ppi;
    int pp_no = pp->pp_no;

    if((*pp_no_map).count(pp_no) == 0) {
      vector<pp_set_t*> *pps_for_no = new vector<pp_set_t*>();
      (*pp_no_map)[pp_no] = pps_for_no;
    }

    (*pp_no_map)[pp_no]->push_back(pp);
  }

  for(auto ppit = (*pp_no_map).begin(); ppit != (*pp_no_map).end(); ++ppit) {
    int pp_no = ppit->first;
    cout << "pp " << pp_no << " has " << ppit->second->size() << " entries" << endl;

    //for(auto ppnit = ppit->second->begin(); ppnit != ppit->second->end(); ++ppnit) {
    //}
  }
}

void insertPpCalls(Module *module, DominatorTree *dt, Loop *pp_loop, Function *f, pp_set_t *pp) {

  cout << "Inserting a pp" << endl;


  BasicBlock *preheader = pp_loop->getLoopPreheader();
  f = preheader->getParent();
  //BasicBlock *preheader = &fi->getEntryBlock();
  if(!preheader) {
    cout << "No preheader, skipping TODO fix me! Add a preheader!" << endl;
    exit(1);
    //      preheader = InsertPreheaderForLoop(loop, dt, li, preserveLcssa);
  } else {
    cout << "Got that preheader" << endl;
    cout << "Created function defs" << endl;

    dt->recalculate(*f);
    BasicBlock *fEntryBlk = &(f->getEntryBlock());
    bool preheaderIsFuncEntry = false;
    if(!dt->dominates(fEntryBlk->getFirstInsertionPt(), preheader)) {
      // Preheader is a bust, try header?
      //cout << "Error: pp_id does not dominate store in function " <<  f->getName().str() << endl;
      if(fEntryBlk == preheader) {
        preheaderIsFuncEntry = true;
        // Blocks are the same, we should be okay to
        cout << "fEntry == preheader" << endl;
      } else {
        cout << "ERROR: preheader pp_id does not dominate store in function " <<  f->getName().str() << ". Skipping PP." << endl;
        exit(1);
      }
    }

    cout << "Found preheader??" << endl; 

    // Create PP ID variable to store from pp_begin and use for pp_end
    IRBuilder<> funcBuilder(f->getEntryBlock().getFirstInsertionPt());
    AllocaInst* pp_id_alloca = funcBuilder.CreateAlloca(IntegerType::get(module->getContext(), 64), nullptr, "");
    pp_id_alloca->setAlignment(8);

    // Create and insert pp_begin call
    IRBuilder<> *pp_builder;
    if(preheaderIsFuncEntry) {
      pp_builder = &funcBuilder;
    } else {
      pp_builder = new IRBuilder<>(preheader->getFirstInsertionPt());
    }
    ArrayRef<Value*> args;

    int ppval;
    double api = pp->metric_vals.at(0);
    if(api > 0.05) ppval = 8;
    else if(api > 0.01) ppval = 6;
    else ppval = 0;

    //uint64_t nins = pp->metric_vals.at(0);
    //uint64_t nrefs = pp->metric_vals.at(1);
    //uint64_t nmiss = pp->metric_vals.at(2);
    //uint64_t nhits = nrefs - nmiss;
    //double ref_ratio = ((double) nrefs) / nins;
    ////uint64_t ratio = nins/nhits;

    //int usability_max = 8;
    //if(ref_ratio > 0.005) {
    //  // Enough LLC usage to make use of PP
    //  double hit_misses = ((double) nhits) / nmiss;
    //  double usability_ratio = hit_misses * ref_ratio * 50;
    //  if(usability_ratio > usability_max) {
    //    ppval = usability_max;
    //    cout << "Usability ratio > 50: " << usability_ratio << ". Using val " << ppval << endl;
    //  } else {
    //    ppval = usability_ratio;
    //  }
    //} else {
    //  ppval = 0;
    //  cout << "Not enough LLC usage, scheduling with pp val " << ppval << endl;
    //}

    

    //double miss_ratio = nmiss/nrefs;
    //double nconcurrent = ((double) 1200) / ratio;
    //if(nconcurrent > 0) {
    //  ppval = 100 / nconcurrent;
    //  if(ppval > 99) ppval = 12;
    //} else {
    //  ppval = 80;
    //}
    cout << "Inserting a pp with ppval: " << ppval << endl;

    ConstantInt* bnestere_pp_no_int = ConstantInt::get(module->getContext(), APInt(32, StringRef(to_string(pp->pp_no).c_str()), 10));
    CallInst*  pp_begin_call = create_pp_begin_call(module, to_string(ppval).c_str(), bnestere_pp_no_int, pp_builder);
    //CallInst*  pp_begin_call = create_pp_begin_call(module, "12", pp_builder);
    StoreInst *pp_id_store = pp_builder->CreateStore(pp_begin_call, pp_id_alloca, false);
    //IRBuilder<> builder(preheader->getFirstInsertionPt());
    //ArrayRef<Value*> args;
    //CallInst*  pp_begin_call = create_pp_begin_call(module, "12", &builder);
    //StoreInst *pp_id_store = builder.CreateStore(pp_begin_call, pp_id_alloca, false);

    // Create pp_end calls
    SmallVector<BasicBlock*, 8> exitBlocks;
    pp_loop->getExitBlocks(exitBlocks);
    for(auto ebi = exitBlocks.begin(); ebi != exitBlocks.end(); ++ebi) {
      if((*ebi)->empty()) continue;
      if(!dt->dominates(pp_id_alloca, *ebi)) {
        cout << "Exit isn't dominated... " << f->getName().str() << endl;
        continue;
      }

      IRBuilder<> builder2((*ebi)->getFirstInsertionPt());
      LoadInst *load_pp_id = builder2.CreateLoad(pp_id_alloca, "llvm_pp_id");
      //ArrayRef<Value*> args(arg);
      //std::vector<Value*> end_pp_args_vec = {load_pp_id, bnestere_pp_no_int};
      //ArrayRef<Value*> *end_pp_args = new ArrayRef<Value*>(end_pp_args_vec);
      builder2.CreateCall2(func_pp_end, load_pp_id, bnestere_pp_no_int, "");
    } // end exit block iteration
  } // end preheader if
  cout << "Finished inserting a pp" << endl;

}

Loop *findLoopForPp(pp_set_t *pp, LoopInfoBase<llvm::BasicBlock, llvm::Loop> *li) {

  int nloops_in_hier = pp->loop_hierarchy.size();
  Loop *pp_loop; // Loop for iterating
  for(int i = 0; i < nloops_in_hier; i++) {
    int loopCtr = 0, loopTrg = pp->loop_hierarchy.at(i) - 1;

    if(i == 0) {
      // Use loopinfobase, not an actual loop yet
      for(auto lii = li->rbegin(); lii != li->rend(); ++lii) {
        if(loopCtr++ == loopTrg) {
          pp_loop = *lii;
          //              cout << "Found li loop" << endl;
          break;
        }
      }
    } else {
      // Here we iterate using the loop children
      for(auto lii = pp_loop->rbegin(); lii != pp_loop->rend(); ++lii) {
        if(loopCtr++ == loopTrg) {
          // Multi loop progress period, requires further analysis on how to insert pp
          pp_loop = *lii;
          //              cout << "Found loop loop" << endl;
          break;
        }
      }
    }
  } // End for looking for the Loop
  return pp_loop;
}

bool function_dominates(Function *A, Function *B) {
  bool dominates = false;

  for(auto abi = A->begin(); abi != A->end(); ++abi) {
    BasicBlock *bb = abi;
    if(bb == nullptr || bb->empty()) continue;
    for(auto ii = bb->begin(); ii != bb->end(); ++ii) {
      Instruction *i = ii;
      if(i == nullptr || !isa<CallInst>(i)) continue;
      CallInst *ci = cast<CallInst>(i);
      Function *calledFunc = ci->getCalledFunction();
      if(calledFunc == B) {
        dominates = true;
      }
      //if(i == nullptr) continue;
//      if(dynamic_cast<CallInst*>(i) == nullptr) continue; // only looking for calls
//      CallInst *ci = (CallInst *) i;
      //cout << A->getName().str() << " inst opcode " << i->getOpcodeName() << endl;

    }
  }
  if(dominates) {
    cout << "A dominates B" << endl;
  } else {

    cout << "A is free of B" << endl;
  }
  return dominates;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    errs() << "Error; Expected usage: " << argv[0] << " {pp cfg file} {LLVM Bitcode filename}\n";
    exit(1);
  }

  set<pp_set_t*> pps_to_set;
  process_pp_file((const char*) argv[1], &pps_to_set); 

  // TODO: Bnestere
  map<int, vector<pp_set_t*>*> pp_no_map;
  set<int> used_pp_nos;
  find_common_dominators(&pps_to_set, &pp_no_map);

  map<string, vector<pp_set_t*>*> pp_fname_map; // keep track of all pps in a function 
  for(auto ppi = pps_to_set.begin(); ppi != pps_to_set.end(); ++ppi) {
    pp_set_t *pp = *ppi;
    string fname = pp->function_name;
    if(pp_fname_map.count(fname) == 0) {
      vector<pp_set_t*> *pps_for_func = new vector<pp_set_t*>();
      pp_fname_map[fname] = pps_for_func;
    }

    pp_fname_map[fname]->push_back(pp);
  }

  LLVMContext context;
  ErrorOr<unique_ptr<MemoryBuffer>> maybeMBuff = MemoryBuffer::getFile(argv[2]);
  if(error_code ec = maybeMBuff.getError()) {
    cout << "Failed to parse file " << argv[2] << endl;
    //  Err.print(argv[0], ec);
    return 1;
  }
  MemoryBuffer *mBuff = maybeMBuff.get().get();


  //unique_ptr<MemoryBuffer> mBuff = maybeMBuff.get().get();
  MemoryBufferRef mbr(mBuff->getBuffer(), mBuff->getBufferIdentifier());
  ErrorOr<Module *> maybeModule = parseBitcodeFile(mbr, context);
  Module *module = maybeModule.get();

  //GlobalVariable *active_pps_gvar = makeActivePpsVariable(module);
  GlobalVariable *apvar = define_active_pps(module);
  GlobalVariable *tpvar = define_trust_pp_nos(module);
  GlobalVariable *dcvar = define_duration_check_pp_nos(module);
  //func_pp_begin = define_pp_begin(module);
  //func_pp_end = define_pp_end(module    );
  func_pp_begin = define_pp_begin(module, apvar, tpvar, dcvar);
  func_pp_end = define_pp_end(module    , apvar, tpvar, dcvar);
  

  //unique_ptr<Module> module = parseIRFile(argv[1], Err, context);

  //if (!module) {
  //  
  //  //Err.print(argv[0], errs());
  //  return 1;
  //}

  DominatorTree dt = DominatorTree();

  map<pp_set_t*, Loop*> pp_to_loop_map;
  //FunctionListType flt = module->getFunctionList();
  for(auto fi = module->begin(); fi != module->end(); ++fi) {
    if(fi->empty()) continue;
    dt.recalculate(*fi); // put all functions in dom tree
    //Check if this function has any progress periods
    if(pp_fname_map.count(fi->getName()) == 0) { 
      //if(fi->getName() != "MDMAIN") { 
      continue;
    }

    cout << "Analyzing loops for func " << fi->getName().str() << endl;
    dt.recalculate(*fi);
    LoopInfoBase<llvm::BasicBlock, llvm::Loop>* li = new LoopInfoBase<llvm::BasicBlock, llvm::Loop>();
    li->releaseMemory();
    li->Analyze(dt);   
    if(li->empty()) continue;

    vector<pp_set_t*> *func_pps = pp_fname_map[fi->getName()];

    for(auto ppi = func_pps->begin(); ppi != func_pps->end(); ++ppi) {
      pp_set_t *pp = *ppi;
      int pp_no = pp->pp_no;

//      if(used_pp_nos.count(pp_no)) {
//        // If this progress period has been written already
//        continue;
//      }
//      used_pp_nos.insert(pp_no);

      vector<pp_set_t*> *loops_in_pp = pp_no_map[pp_no];
      Loop *pp_loop = findLoopForPp(pp, li);
      pp_to_loop_map[pp] = pp_loop;

//      insertPpCalls(module, &dt, pp_loop, fi);
    }
  }

    cout << "Finding the actual loops to insert" << endl;
  
  vector<pp_loop_t*> pploops_to_insert;
  vector<Loop*> loops_to_insert;
  vector<Function*> funcs_to_insert;
  set<Loop*> standalone_loops; // mimics loops_to_insert at this point, but we remove loops from here if dominated
  set<pp_loop_t*> standalone_pploops; // mimics loops_to_insert at this point, but we remove loops from here if dominated
  for(auto ppnit = pp_no_map.begin(); ppnit != pp_no_map.end(); ++ppnit) {
    int pp_no = ppnit->first;
    cout << "Analyzing loops to insert for pp_no " << pp_no << endl;
    vector<pp_set_t*> *pps_for_no = ppnit->second;

    vector<pp_loop_t*> pploops_for_pp;
    vector<Loop*> loops_for_pp;
  //  vector<Function*> funcs_for_pp;
    set<Function*> unique_funcs;
    for(auto ppit = pps_for_no->begin(); ppit != pps_for_no->end(); ++ppit) {
      pp_set_t *pp = *ppit; 
      Loop *pp_loop = pp_to_loop_map[pp];
      pp_loop_t *ppl = new pp_loop_t;
      ppl->loop = pp_loop;
      ppl->pp = pp;
      loops_for_pp.push_back(pp_loop);
      pploops_for_pp.push_back(ppl);
      Function *f = pp_loop->getHeader()->getParent();
      //funcs_for_pp.push_back(f);
      unique_funcs.insert(f);

      //insertPpCalls(module, &dt, pp_loop, f);
    }

    if(loops_for_pp.size() == 1) {
      // Just the single loop, easy, add it
      //cout << "Easy, 1 loop, inserting prog per in func " << funcs_for_pp.at(0)->getName().str() << endl;
      loops_to_insert.push_back(loops_for_pp.at(0));
      pploops_to_insert.push_back(pploops_for_pp.at(0));
      standalone_loops.insert(loops_for_pp.at(0));
      standalone_pploops.insert(pploops_for_pp.at(0));
     // funcs_to_insert.push_back(funcs_for_pp.at(0));
      //insertPpCalls(module, &dt, loops_for_pp.at(0), funcs_for_pp.at(0));

    } else {
      // Multi loop progress period, requires further analysis on how to insert pp
      //for(auto lit = loops_for_pp.begin(); lit != loops_for_pp.end(); ++lit) {
      //  loops_to_insert.push_back(*lit);
      //  standalone_loops.insert(*lit);
      //}
      for(auto lit = pploops_for_pp.begin(); lit != pploops_for_pp.end(); ++lit) {
        pploops_to_insert.push_back(*lit);
        standalone_pploops.insert(*lit);
      }
//      if(unique_funcs.size() > 1) {
//        // progress period spans loops from multiple functions, analyze DT to find common call
//        cout << "PP " << pp_no << " spans multiple functions:" << endl;
//        for(auto fit = unique_funcs.begin(); fit != unique_funcs.end(); ++fit) {
//        cout << "\t" << (*fit)->getName().str() << endl;
//        }
//      } else {
//        // All in the same function
//        Function *f = *unique_funcs.begin();
//        if(!f) {
//          cout << "Unique func doesn't exist" << endl;
//          exit(1);
//        }
//        cout << "PP " << pp_no << " is only one function: " << (*unique_funcs.begin())->getName().str() << endl;
//      }
    }
  }

    cout << "Finding dominators" << endl;

  set<Loop*> dominator_loops;
  set<Loop*> dominated_loops;
  set<pp_loop_t*> dominator_pploops;
  set<pp_loop_t*> dominated_pploops;
  // Find if there are any dominations between progress periods
  for(int i = 0; i < pploops_to_insert.size(); i++) {
    pp_loop_t *ippl = pploops_to_insert.at(i);
    Loop *iLoop = ippl->loop;
    BasicBlock *iBlock = iLoop->getLoopPreheader();

    Function *iFunc = iBlock->getParent();
    cout << "Analyzing dom stuff for i " << i << " and func " << iFunc->getName().str() << endl;


    for(int j = i + 1; j < pploops_to_insert.size(); j++) {
      pp_loop_t *jppl = pploops_to_insert.at(i);
      Loop *jLoop = jppl->loop;

      BasicBlock *jBlock = jLoop->getLoopPreheader();
      Function *jFunc = jBlock->getParent();


      if(function_dominates(iFunc, jFunc)) {
      //if(dt.properlyDominates(iBlock->getFirstNonPHIOrDbgOrLifetime(), jBlock)) {
        dominator_pploops.insert(ippl);
        dominated_pploops.insert(jppl);
        standalone_pploops.erase(ippl);
        standalone_pploops.erase(jppl);
        cout << iBlock->getParent()->getName().str() << " dominates " << jBlock->getParent()->getName().str() << endl;
      //} else if(dt.properlyDominates(jBlock->getFirstNonPHIOrDbgOrLifetime(), iBlock)) {
      } else if(function_dominates(jFunc, iFunc)) {
        dominator_pploops.insert(jppl);
        dominated_pploops.insert(ippl);
        standalone_pploops.erase(ippl);
        standalone_pploops.erase(jppl);
        cout << "jBlock dominates iBlock" << endl;
      } else {
        cout << "No domination" << endl;
      }
    }
  }
    cout << "Inserting PP Calls" << endl;
  // We want to insert pps at the leafs, so if a loop is dominated but never a dominator, add it
  for(auto dedi = dominated_pploops.begin(); dedi != dominated_pploops.end(); ++dedi) {
    pp_loop_t *dominated_ppl = *dedi;
    Loop *dominated_loop = dominated_ppl->loop;
    if(dominator_loops.count(dominated_loop)) continue; // Loop is also a dominator
    Function *f = dominated_loop->getHeader()->getParent();
    insertPpCalls(module, &dt, dominated_loop, f, dominated_ppl->pp);
  }

  for(auto ltii = standalone_pploops.begin(); ltii != standalone_pploops.end(); ++ltii) {
    pp_loop_t *standalone_ppl = *ltii;
    Loop *loop = standalone_ppl->loop;
    Function *f = loop->getHeader()->getParent();
    insertPpCalls(module, &dt, loop, f, standalone_ppl->pp);
  }

//  // Find if there are any dominations between progress periods
//  for(int i = 0; i < loops_to_insert.size(); i++) {
//    Loop *iLoop = loops_to_insert.at(i);
//    BasicBlock *iBlock = iLoop->getLoopPreheader();
//
//    Function *iFunc = iBlock->getParent();
//    cout << "Analyzing dom stuff for i " << i << " and func " << iFunc->getName().str() << endl;
//
//
//    for(int j = i + 1; j < loops_to_insert.size(); j++) {
//      Loop *jLoop = loops_to_insert.at(j);
//
//      BasicBlock *jBlock = jLoop->getLoopPreheader();
//      Function *jFunc = jBlock->getParent();
//
//
//      if(function_dominates(iFunc, jFunc)) {
//      //if(dt.properlyDominates(iBlock->getFirstNonPHIOrDbgOrLifetime(), jBlock)) {
//        dominator_loops.insert(iLoop);
//        dominated_loops.insert(jLoop);
//        standalone_loops.erase(iLoop);
//        standalone_loops.erase(jLoop);
//        cout << iBlock->getParent()->getName().str() << " dominates " << jBlock->getParent()->getName().str() << endl;
//      //} else if(dt.properlyDominates(jBlock->getFirstNonPHIOrDbgOrLifetime(), iBlock)) {
//      } else if(function_dominates(jFunc, iFunc)) {
//        dominator_loops.insert(jLoop);
//        dominated_loops.insert(iLoop);
//        standalone_loops.erase(iLoop);
//        standalone_loops.erase(jLoop);
//        cout << "jBlock dominates iBlock" << endl;
//      } else {
//        cout << "No domination" << endl;
//      }
//    }
//  }

//  // We want to insert pps at the leafs, so if a loop is dominated but never a dominator, add it
//  for(auto dedi = dominated_loops.begin(); dedi != dominated_loops.end(); ++dedi) {
//    Loop *dominated_loop = *dedi;
//    if(dominator_loops.count(dominated_loop)) continue; // Loop is also a dominator
//    Function *f = dominated_loop->getHeader()->getParent();
//    insertPpCalls(module, &dt, dominated_loop, f);
//  }
//
//  for(auto ltii = standalone_loops.begin(); ltii != standalone_loops.end(); ++ltii) {
//    Loop *loop = *ltii;
//    Function *f = loop->getHeader()->getParent();
//    insertPpCalls(module, &dt, loop, f);
//  }

  //llvm::verifyModule((const Module&) module);
  error_code EC;
  raw_fd_ostream OS("module.bc", EC, sys::fs::F_None);
  WriteBitcodeToFile(module, OS);
  OS.flush();

  cout << "Done" << endl;

}


  //      int nloops_in_hier = pp->loop_hierarchy.size();
  //      Loop *pp_loop; // Loop for iterating
  //      for(int i = 0; i < nloops_in_hier; i++) {
  //        int loopCtr = 0, loopTrg = pp->loop_hierarchy.at(i) - 1;
  //
  //        if(i == 0) {
  //          // Use loopinfobase, not an actual loop yet
  //          for(auto lii = li->rbegin(); lii != li->rend(); ++lii) {
  //            if(loopCtr++ == loopTrg) {
  //              pp_loop = *lii;
  //              //              cout << "Found li loop" << endl;
  //              break;
  //            }
  //          }
  //        } else {
  //          // Here we iterate using the loop children
  //          for(auto lii = pp_loop->rbegin(); lii != pp_loop->rend(); ++lii) {
  //            if(loopCtr++ == loopTrg) {
  //              pp_loop = *lii;
  //              //              cout << "Found loop loop" << endl;
  //              break;
  //            }
  //          }
  //        }
  //      } // End for looking for the Loop
  //      cout << "Found loop" << endl;

  //      BasicBlock *preheader = pp_loop->getLoopPreheader();
  //      //BasicBlock *preheader = &fi->getEntryBlock();
  //      if(!preheader) {
  //        cout << "No preheader, skipping TODO fix me! Add a preheader!" << endl;
  //        exit(1);
  //        //      preheader = InsertPreheaderForLoop(loop, dt, li, preserveLcssa);
  //      } else {
  //        Function *func_pp_begin = define_pp_begin(module);
  //        Function *func_pp_end = define_pp_end(module);
  //
  //        IRBuilder<> funcBuilder((&fi->getEntryBlock())->getFirstInsertionPt());
  //        AllocaInst* pp_id_alloca = funcBuilder.CreateAlloca(IntegerType::get(module->getContext(), 64), nullptr, "");
  //        pp_id_alloca->setAlignment(8);
  //
  //        IRBuilder<> builder(preheader->getFirstInsertionPt());
  //        ArrayRef<Value*> args;
  //        CallInst*  pp_begin_call = create_pp_begin_call(module, "50", &builder);
  //        if(!dt.dominates(pp_id_alloca, preheader)) {
  //          cout << "Error: pp_id does not dominate store in function " <<  fi->getName().str() << endl;
  //          exit(1);
  //        }
  //        StoreInst *pp_id_store = builder.CreateStore(pp_begin_call, pp_id_alloca, false);
  //
  //        SmallVector<BasicBlock*, 8> exitBlocks;
  //        pp_loop->getExitBlocks(exitBlocks);
  //        for(auto ebi = exitBlocks.begin(); ebi != exitBlocks.end(); ++ebi) {
  //          if((*ebi)->empty()) continue;
  //
  //          if(!dt.dominates(pp_id_alloca, *ebi)) continue;
  //
  //          IRBuilder<> builder2((*ebi)->getFirstInsertionPt());
  //          //Value *arg = builder2.CreateLoad(pp_id_alloca, "llvm_pp_id")->getPointerOperand();
  //          LoadInst *load_pp_id = builder2.CreateLoad(pp_id_alloca, "llvm_pp_id");
  //          //ArrayRef<Value*> args(arg);
  //          builder2.CreateCall(func_pp_end, load_pp_id, "");
  //        } // end exit block iteration
  //      } // end preheader if

CallInst* create_pp_begin_call(Module *mod, const char *wssVal, ConstantInt *bnestere_pp_no_int, IRBuilder<> *builder) {
    //bnestere
    StructType *StructTy_struct__pp_user_t = mod->getTypeByName("struct._pp_user_t");
    PointerType* PointerTy_1 = PointerType::get(StructTy_struct__pp_user_t, 0);
    std::vector<Type*>FuncTy_0_args;
    FuncTy_0_args.push_back(PointerTy_1);
    FunctionType* FuncTy_0 = FunctionType::get(
        /*Result=*/IntegerType::get(mod->getContext(), 64),
        /*Params=*/FuncTy_0_args,
        /*isVarArg=*/false);
    ConstantInt* const_int32_10 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("1"), 10));
    ConstantInt* const_int32_11 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("0"), 10));
    ConstantInt* const_int32_12 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("2"), 10));
    ConstantInt* bnestere_wss_int = ConstantInt::get(mod->getContext(), APInt(32, StringRef(wssVal), 10));
    //ConstantInt* bnestere_pp_no_int = ConstantInt::get(mod->getContext(), APInt(32, StringRef(pp_no), 10));

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

    // Block entry (bb)
    //AllocaInst* ptr_user_t = new AllocaInst(StructTy_struct__pp_user_t, "user_t", bb);
    AllocaInst* ptr_user_t = builder->CreateAlloca(StructTy_struct__pp_user_t, nullptr, "user_t");
    ptr_user_t->setAlignment(4);
    std::vector<Value*> ptr_wss_27_indices;
    ptr_wss_27_indices.push_back(const_int32_11);
    ptr_wss_27_indices.push_back(const_int32_11);
    //Instruction* ptr_wss_27 = GetElementPtrInst::Create(ptr_user_t, ptr_wss_27_indices, "wss", bb);
    IRBuilderBase::InsertPoint ip;
    Instruction *ptr_wss_27 = GetElementPtrInst::Create(ptr_user_t, ptr_wss_27_indices, "wss");
    ip = builder->saveIP();
    ip.getBlock()->getInstList().insert(ip.getPoint(), ptr_wss_27);
    //Instruction* ptr_wss_27 = GetElementPtrInst::Create(ptr_user_t, ptr_wss_27_indices, "wss", *(builder->GetInsertPoint()));
    //Instruction* ptr_wss_27 = builder->CreateGEP(ptr_user_t, ptr_wss_27_indices, "wss");
    //StoreInst* void_28 = new StoreInst(bnestere_wss_int, ptr_wss_27, false, bb);
    StoreInst* void_28 = builder->CreateStore(bnestere_wss_int, ptr_wss_27, false);
    void_28->setAlignment(4);
    std::vector<Value*> ptr_reuse_29_indices;
    ptr_reuse_29_indices.push_back(const_int32_11);
    ptr_reuse_29_indices.push_back(const_int32_10);
    //Instruction* ptr_reuse_29 = GetElementPtrInst::Create(ptr_user_t, ptr_reuse_29_indices, "reuse", bb);
    Instruction* ptr_reuse_29 = GetElementPtrInst::Create(ptr_user_t, ptr_reuse_29_indices, "reuse");
    ip = builder->saveIP();
    ip.getBlock()->getInstList().insert(ip.getPoint(), ptr_reuse_29);
    //Instruction* ptr_reuse_29 = builder->CreateGEP(ptr_user_t, ptr_reuse_29_indices, "reuse");
    //StoreInst* void_30 = new StoreInst(const_int32_10, ptr_reuse_29, false, bb);
    StoreInst* void_30 = builder->CreateStore(const_int32_10, ptr_reuse_29, false);
    void_30->setAlignment(4);
    std::vector<Value*> ptr_resource_31_indices;
    ptr_resource_31_indices.push_back(const_int32_11);
    ptr_resource_31_indices.push_back(const_int32_12);
    //Instruction* ptr_resource_31 = GetElementPtrInst::Create(ptr_user_t, ptr_resource_31_indices, "resource", bb);
    Instruction* ptr_resource_31 = GetElementPtrInst::Create(ptr_user_t, ptr_resource_31_indices, "resource");
    ip = builder->saveIP();
    ip.getBlock()->getInstList().insert(ip.getPoint(), ptr_resource_31);
    //Instruction* ptr_resource_31 = builder->CreateGEP(ptr_user_t, ptr_resource_31_indices, "resource");
    //StoreInst* void_32 = new StoreInst(const_int32_11, ptr_resource_31, false, bb);
    StoreInst* void_32 = builder->CreateStore(const_int32_11, ptr_resource_31, false);
    void_32->setAlignment(4);
    //CallInst* int64_call = CallInst::Create(func_pp_begin, ptr_user_t, "call", bb);
    CallInst* int64_call = builder->CreateCall2(func_pp_begin, ptr_user_t, bnestere_pp_no_int, "call");
    int64_call->setCallingConv(CallingConv::C);
    int64_call->setTailCall(false);
    AttributeSet int64_call_PAL;
    int64_call->setAttributes(int64_call_PAL);

    return int64_call;

    //ReturnInst::Create(mod->getContext(), bb);
    //return func_call_begg;
  }
