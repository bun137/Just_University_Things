   | op[1:0] | i0[15:0] | i1[15:0] | Output | cout |
   |---------|----------|----------|--------|------|
   | TESTVECTOR0 | 2’b00 | 16’h0000 | 16’h0000 | 0000 | 0 |
   | TESTVECTOR1 | 2’b00 | 16’haa55 | 16’h55aa | 0000 | 0 |
   | TESTVECTOR2 | 2’b00 | 16'hffff | 16'h0001 | 0000 | 0 |
   | TESTVECTOR3 | 2’b00 | 16'h0001 | 16'h7fff | 0000 | 1 |
   | TESTVECTOR4 | 2`b01 | 16'h0000 | 16'h0000 | 0000 | 0 |
   | TESTVECTOR5 | 2`b01 | 16’haa55 | 16’h55aa | ffff | 1 |
   | TESTVECTOR6 | 2`b01 | 16'hffff | 16'h0001 | Ab54 | 1 |
   | TESTVECTOR7 | 2`b01 | 16'h0001 | 16'h7fff | 0001 | 1 |
   | TESTVECTOR8 | 2`b10 | 16’h0000 | 16’h0000 | 7ffd | 0 |
   | TESTVECTOR9 | 2`b10 | 16’haa55 | 16’h55aa | 0000 | 0 |
   | TESTVECTOR10 | 2`b10 | 16'hffff | 16'h0001 | 0000 | 0 |
   | TESTVECTOR11 | 2`b10 | 16'h0001 | 16'h7fff | 0000 | 1 |
   | TESTVECTOR12 | 2’b11 | 16’h0000 | 16’h0000 | 8000 | 0 |
   | TESTVECTOR13 | 2’b11 | 16’haa55 | 16’h55aa | ffff | 1 |
   | TESTVECTOR14 | 2’b11 | 16'hffff | 16'h0001 | Ab54 | 1 |
   | TESTVECTOR15 | 2’b11 | 16'h0001 | 16'h7fff | 0001 | 1 |
 
