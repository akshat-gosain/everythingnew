`include "half_adder.v"
module full_adder (input x, input y, input z, output S, output C)
wire a1,a2,a3;
wire o1;

xor x1(S,A,B,Cin);

and and1(a1,A,B);
and and2(a2,B,Cin);
and and3(a3,A,Cin);

or or1(o1,a1,a2);
or or2(Cout,a3,o1);
endmodule
