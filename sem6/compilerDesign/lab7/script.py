llvm = r'''@sl = constant [30 x i8] c"Hi I'm Shreya, PES2UG22CS209\0a\00"

declare i32 @printf(i8*, ...)

define i32 @main() {
    %sl_ptr = getelementptr [30 x i8], [30 x i8]* @sl, i32 0, i32 0
    call i32 @printf(i8* %sl_ptr)
    ret i32 0
}'''

with open("output.ll", 'w') as file:
    file.write(llvm)

