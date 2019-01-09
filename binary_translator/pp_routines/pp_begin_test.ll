; ModuleID = 'pp_begin_test.bc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.timespec = type { i64, i64 }
%struct._pp_user_t = type { i32, i32, i32 }

@trust_pp_nos = external global [128 x i64]
@duration_check_pp_nos = external global [1024 x [128 x %struct.timespec]]
@active_pps = external global [1024 x [128 x i64]]
@.str = private unnamed_addr constant [16 x i8] c"Ignoring PP %d\0A\00", align 1
@.str1 = private unnamed_addr constant [29 x i8] c"Testing the waters... pp %d\0A\00", align 1
@.str2 = private unnamed_addr constant [57 x i8] c"Beginning progress period %d: wss %d, reuse %d, rsrc %d\0A\00", align 1

; Function Attrs: nounwind uwtable
define internal i64 @pp_begin(%struct._pp_user_t* %user_d, i32 %pp_no) #0 {
entry:
  %retval = alloca i64, align 8
  %user_d.addr = alloca %struct._pp_user_t*, align 8
  %pp_no.addr = alloca i32, align 4
  %tid = alloca i32, align 4
  %pp_id = alloca i64, align 8
  %spec = alloca %struct.timespec*, align 8
  store %struct._pp_user_t* %user_d, %struct._pp_user_t** %user_d.addr, align 8
  store i32 %pp_no, i32* %pp_no.addr, align 4
  %call = call i64 (i64, ...)* @syscall(i64 186) #3
  %and = and i64 %call, 1023
  %conv = trunc i64 %and to i32
  store i32 %conv, i32* %tid, align 4
  store i64 -1, i64* %pp_id, align 8
  %0 = load i32* %pp_no.addr, align 4
  %idxprom = sext i32 %0 to i64
  %arrayidx = getelementptr inbounds [128 x i64]* @trust_pp_nos, i32 0, i64 %idxprom
  %1 = load i64* %arrayidx, align 8
  %cmp = icmp eq i64 %1, -1
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %2 = load i32* %pp_no.addr, align 4
  %call2 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([16 x i8]* @.str, i32 0, i32 0), i32 %2)
  store i64 -1, i64* %retval
  br label %return

if.else:                                          ; preds = %entry
  %3 = load i32* %pp_no.addr, align 4
  %idxprom3 = sext i32 %3 to i64
  %arrayidx4 = getelementptr inbounds [128 x i64]* @trust_pp_nos, i32 0, i64 %idxprom3
  %4 = load i64* %arrayidx4, align 8
  %cmp5 = icmp eq i64 %4, 0
  br i1 %cmp5, label %if.then7, label %if.end

if.then7:                                         ; preds = %if.else
  %5 = load i32* %pp_no.addr, align 4
  %call8 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([29 x i8]* @.str1, i32 0, i32 0), i32 %5)
  %6 = load i32* %pp_no.addr, align 4
  %idxprom9 = sext i32 %6 to i64
  %7 = load i32* %tid, align 4
  %idxprom10 = sext i32 %7 to i64
  %arrayidx11 = getelementptr inbounds [1024 x [128 x %struct.timespec]]* @duration_check_pp_nos, i32 0, i64 %idxprom10
  %arrayidx12 = getelementptr inbounds [128 x %struct.timespec]* %arrayidx11, i32 0, i64 %idxprom9
  store %struct.timespec* %arrayidx12, %struct.timespec** %spec, align 8
  %8 = load %struct.timespec** %spec, align 8
  %call13 = call i32 @clock_gettime(i32 0, %struct.timespec* %8) #3
  br label %if.end

if.end:                                           ; preds = %if.then7, %if.else
  br label %if.end14

if.end14:                                         ; preds = %if.end
  %9 = load i32* %pp_no.addr, align 4
  %idxprom15 = sext i32 %9 to i64
  %10 = load i32* %tid, align 4
  %idxprom16 = sext i32 %10 to i64
  %arrayidx17 = getelementptr inbounds [1024 x [128 x i64]]* @active_pps, i32 0, i64 %idxprom16
  %arrayidx18 = getelementptr inbounds [128 x i64]* %arrayidx17, i32 0, i64 %idxprom15
  %11 = load i64* %arrayidx18, align 8
  %cmp19 = icmp eq i64 %11, 0
  br i1 %cmp19, label %if.then21, label %if.end28

if.then21:                                        ; preds = %if.end14
  %12 = load i32* %tid, align 4
  %13 = load i32* %pp_no.addr, align 4
  %add = add nsw i32 %12, %13
  %conv22 = sext i32 %add to i64
  store i64 %conv22, i64* %pp_id, align 8
  %14 = load i64* %pp_id, align 8
  %15 = load i32* %pp_no.addr, align 4
  %idxprom23 = sext i32 %15 to i64
  %16 = load i32* %tid, align 4
  %idxprom24 = sext i32 %16 to i64
  %arrayidx25 = getelementptr inbounds [1024 x [128 x i64]]* @active_pps, i32 0, i64 %idxprom24
  %arrayidx26 = getelementptr inbounds [128 x i64]* %arrayidx25, i32 0, i64 %idxprom23
  store i64 %14, i64* %arrayidx26, align 8
  %17 = load i32* %pp_no.addr, align 4
  %18 = load %struct._pp_user_t** %user_d.addr, align 8
  %wss = getelementptr inbounds %struct._pp_user_t* %18, i32 0, i32 0
  %19 = load i32* %wss, align 4
  %20 = load %struct._pp_user_t** %user_d.addr, align 8
  %reuse = getelementptr inbounds %struct._pp_user_t* %20, i32 0, i32 1
  %21 = load i32* %reuse, align 4
  %22 = load %struct._pp_user_t** %user_d.addr, align 8
  %resource = getelementptr inbounds %struct._pp_user_t* %22, i32 0, i32 2
  %23 = load i32* %resource, align 4
  %call27 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([57 x i8]* @.str2, i32 0, i32 0), i32 %17, i32 %19, i32 %21, i32 %23)
  br label %if.end28

if.end28:                                         ; preds = %if.then21, %if.end14
  %24 = load i64* %pp_id, align 8
  store i64 %24, i64* %retval
  br label %return

return:                                           ; preds = %if.end28, %if.then
  %25 = load i64* %retval
  ret i64 %25
}

; Function Attrs: nounwind
declare i64 @syscall(i64, ...) #1

declare i32 @printf(i8*, ...) #2

; Function Attrs: nounwind
declare i32 @clock_gettime(i32, %struct.timespec*) #1

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.6.2 (tags/RELEASE_362/final)"}
