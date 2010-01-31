#!/bin/bash
# +AMDG

var=`./tgmconv -k 8  -iTm  -os 1 | ../dec/dec -k 8`;
echo "0.17361111 --- $var";
var=`./tgmconv -k 8  -oTm  -is 1`;
echo "5;915343X1 --- $var";
var=`./tgmconv -k 8  -o3^Tm  -imin 5`;
echo "1;00000000 --- $var";
var=`./tgmconv -k 8 -o3_Tm   -ims 1`;
echo "9;E53326X4 --- $var";
var=`./tgmconv -k 10 -i3_Tm   -oms 1 | ../dec/dec -k 10`;
echo "0.1004693929 --- $var";
var=`./tgmconv -k 10 -iG   -om/s2 1 | ../dec/dec -k 10`;
echo "9.8100494007 --- $var";
var=`./tgmconv -k 8 -im/s2   -oG 1`;
echo "0;12819015 --- $var";
var=`./tgmconv -k 8  -ift/s2  -oG 1`;
echo "0;04583309 --- $var";
var=`./tgmconv -k 8  -iG  -o ft/s2 1 | ../dec/dec -k 8`;
echo "32.18520142 --- $var";
var=`./tgmconv -k10 -om   -iGf 1 | ../dec/dec -k 10`;
echo "0.2956829126 --- $var";
var=`./tgmconv -k 8 -oGf -im   1`;
echo "3;4701219X --- $var";
var=`./tgmconv -k10  -o ft  -iGf 1 | ../dec/dec -k 10`;
echo "0.9700882959 --- $var";
var=`./tgmconv -k8  -i ft  -oGf 1`;
echo "1;045345X0 --- $var";
var=`./tgmconv -k10 -o in -iGf   1 | ../dec/dec -k 10`;
echo "11.6410595508 --- $var";
var=`./tgmconv -k8 -i in -oGf   1`;
echo "0;1045235X --- $var";
var=`./tgmconv -k10   -o mm -i2_Gf 1 | ../dec/dec -k 10`;
echo "2.0533535596 --- $var";
var=`./tgmconv -k8 -i mm   -o2_Gf 1`;
echo "0;5X16727E --- $var";
var=`./tgmconv -k10 -om   -i6_Gf 1 | ../dec/dec -ek 10`;
echo "9.902360916e-8 --- $var";
var=`./tgmconv -k8   -o6_Gf -ium 1`;
echo "X;12247357 --- $var";
var=`./tgmconv -k10 -okm   -i4^Gf 1 | ../dec/dec -k 10`;
echo "6.1312808754 --- $var";
var=`./tgmconv -k 8 -oGf   -ikm 1`;
echo "1E5X;00233X8 --- $var";
var=`./tgmconv -k 10  -omi  -i4^Gf 1 | ../dec/dec -k 10`;
echo "3.8098013075 --- $var";
var=`./tgmconv -k8 -o 3^Gf   -imi 1`;
echo "3;1969786 --- $var";
var=`./tgmconv -k10 -om/s   -iVl 1 | ../dec/dec -k 10`;
echo "1.7031335765 --- $var";
var=`./tgmconv -k8 -oVl   -im/s 1`
echo "0;7067255X --- $var";
var=`./tgmconv -k3 -iVl -okm/hr   1 | ../dec/dec -k 3`;
echo "6.131 --- $var";
var=`./tgmconv -k10 -oft/s   -iVl 1 | ../dec/dec -k 10`;
echo "5.5877085843 --- $var";
var=`./tgmconv -k8 -o1_Vl -ift/s   1`;
echo "2;1930041E --- $var";
var=`./tgmconv -k8 -oSf   -im2 1`;
echo "E;5308E881 --- $var";
var=`./tgmconv -k8 -om2   -iSf 1 | ../dec/dec -k 10`;
echo "0.087428384796 --- $var";
var=`./tgmconv -k8   -oft2 -iSf 1 | ../dec/dec -k 10`;
echo "0.9410713018 --- $var";
#var=`./tgmconv -k8 -o4^Sf   -iha 1`;
#echo "5;62373E49 --- $var";
#var=`./tgmconv -k10  -i4^Sf  -oha 1 | ../dec/dec -k 10`;
#echo "0.1812914987 --- $var";
#var=`./tgmconv -k10  -i4^Sf  -oacre 1 | ../dec/dec -k 10`;
#echo "0.4479810495 --- $var";
#var=`./tgmconv -k8  -o4^Sf  -iacre 1`;
#echo "2;29538098 --- $var";
var=`./tgmconv -k8 -o2_Mz -ikg 1`;
echo "5;6X1X4457 --- $var";
var=`./tgmconv -k10  -iMz  -okg 1 | ../dec/dec -k 10`;
echo "25.8503556494 --- $var";
var=`./tgmconv -k8 -o5_Mz -ig 1`;
echo "9;7615XXEX --- $var";
var=`./tgmconv -k10  -i4_Mz  -og 1 | ../dec/dec -k 10`;
echo "1.2466413797 --- $var";
var=`./tgmconv -k8 -o2_Mz -ilb 1`;
echo "--> 2;63X2748X --- $var";
var=`./tgmconv -k10  -iMz  -olbs 1 | ../dec/dec -k 10`;
echo "56.9902828681 --- $var";
var=`./tgmconv -k8 -o1^Mz -itoni 1`;
echo "3;28263384 --- $var";
var=`./tgmconv -k10  -i2^Mz  -otoni 1 | ../dec/dec -k 10`;
echo "3.7224512135 --- $var";
var=`./tgmconv -k8 -o3_Mz -ioz 1`;
echo "1;X8X7E668 --- $var";
var=`./tgmconv -k10  -i3_Mz  -ooz 1 | ../dec/dec -k 10`;
echo "0.5276878043 --- $var";
var=`./tgmconv -k8 -o6^Sf   -ikm2 1`;
echo "3;9E7210XE --- $var";
var=`./tgmconv -k10  -i6^Sf  -okm2 1 | ../dec/dec -k 10`;
echo "0.2610597581 --- $var";
var=`./tgmconv -k8 -o5_Sf   -imm2 1`;
echo "2;X1X127X9 --- $var";
var=`./tgmconv -k10  -i4_Sf  -omm2 1 | ../dec/dec -k 10`;
echo "4.2162608409 --- $var";
var=`./tgmconv -k8 -o2_Vm -iL 1`;
echo "5;6X1X4457 --- $var";
var=`./tgmconv -k10  -iVm  -oL 1 | ../dec/dec -k 10`;
echo "25.8503556494 --- $var";
var=`./tgmconv -k8 -o5_Vm -imL 1`;
echo "9;7615XXEX --- $var";
var=`./tgmconv -k10  -i4_Vm -omL 1 | ../dec/dec -k 10`;
echo "1.2466413797 --- $var";
var=`./tgmconv -iVl -omi/hr 1 | ../dec/dec -k10`;
echo "3.8098013075 --- $var";

var=`./tgmconv -k8 -ift3 -oVm 1`;
echo "1;1189X583 --- $var";
var=`./tgmconv -k10 -iVm -oft3 1 | ../dec/dec -k 10`;
echo "0.9129222555 --- $var";
var=`./tgmconv -k8 -igali -o1_Vm 1`;
echo "2;13X69515 --- $var";
var=`./tgmconv -k10 -iVm -ogali 1 | ../dec/dec -k 10`;
echo "5.6864459111 --- $var";
var=`./tgmconv -k8 -igalc -o1_Vm 1`;
echo "1;91051389 --- $var";
var=`./tgmconv -k10 -iVm -ogalc 1 | ../dec/dec -k 10`;
echo "6.8290818133 --- $var";
var=`./tgmconv -k8 -ipti -o2_Vm 1`;
echo "3;1E9X22E1 --- $var";
var=`./tgmconv -k10 -i2_Vm -opti 1 | ../dec/dec -k 10`;
echo "0.3159136617 --- $var";
var=`./tgmconv -k8 -iptc -o2_Vm 1`;
echo "2;77677E72 --- $var";
var=`./tgmconv -k10 -i2_Vm -optc 1 | ../dec/dec -k 10`;
echo "0.3793934341 --- $var";
