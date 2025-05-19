import os

llvm_string_def = r'''
@s1 = constant [43 x i8] c"Hi I'm Shreya and my SRN is PES2UG22CS209\0a\00"

declare i32 @printf(i8*, ...)
'''

llvm_main = r'''
define i32 @main() {
%s1_ptr = getelementptr [4 x i8], [4 x i8]* @s1, i32 0, i32 0
'''

llvm_print = r'''
  call i32(i8*, ...) @printf(i8* %s1_ptr)
'''

llvm_ret = r'''
  ret i32 0
}
'''


with open("output.ll", "w") as file:
    file.write(llvm_string_def)
    file.write(llvm_main)
    file.write(llvm_print)
    file.write(llvm_print)
    file.write(llvm_print)
    file.write(llvm_ret)

os.system("lli output.ll")
# os.system("rm output.ll")

