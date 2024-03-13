module or_test;
reg a,b;
wire y;
or  or_test(y,a,b);
initial
begin
#000 a=0;b=0;
#100 a=0;b=1;
#100 a=1;b=0;
#100 a=1;b=1;
end
initial
begin
$monitor($time,"a=%b, b=%b, y=%b", a,b, y);
end
initial
begin
$dumpfile ("or2_test.vcd");
 $dumpvars (0, or_test);
end
endmodule
