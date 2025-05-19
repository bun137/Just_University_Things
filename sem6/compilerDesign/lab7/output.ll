
@s1 = constant [43 x i8] c"Hi I'm Shreya and my SRN is PES2UG22CS209\0a\00"

declare i32 @printf(i8*, ...)

define i32 @main() {
%s1_ptr = getelementptr [4 x i8], [4 x i8]* @s1, i32 0, i32 0

  call i32(i8*, ...) @printf(i8* %s1_ptr)

  call i32(i8*, ...) @printf(i8* %s1_ptr)

  call i32(i8*, ...) @printf(i8* %s1_ptr)

  ret i32 0
}
