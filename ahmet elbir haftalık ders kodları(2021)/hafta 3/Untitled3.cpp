#include<stdio.h>
int main(){
	
	int ar[5]={1,2};
	int *p=ar;
	int i;
	//p=ar[0];
	printf("%d\n",*p);
	printf("%d\n",ar[0]);//1
	printf("%d\n",&ar[0]);//address
	printf("%d\n",ar);//address
	//printf("%d\n",&&ar[0]);//illegal
	p++;
	printf("%d---%d\n",p,*p);
	p--;
	p+=3;
	printf("%d---%d\n",p,*p);
	*p=*p+5;//ar[3]+=5;
	printf("%d---%d\n",p,*p);
	printf("==============\n");
	for(i=0;i<5;i++){
		printf("%d----%d\n",ar[i],&ar[i]);
	}
	printf("==============\n");
	for(p=&ar[0],i=0;i<5;i++,p++){
		printf("%d----%d\n",*p,p);
	}
	
	printf("==============\n");
	for(p=ar,i=0;i<5464;i++){
		printf("%d %d----%d\n",i,*(p+i),(p+i));
	}
	
	printf("%d----%d\n",sizeof(int),sizeof(short));
	printf("%d----%d",sizeof(int*),sizeof(short*));
	return 0;
}
/*
output:
1
1
6487552
6487552
6487556---2
6487564---0
6487564---5
==============
1----6487552
2----6487556
0----6487560
5----6487564
0----6487568
==============
1----6487552
2----6487556
0----6487560
5----6487564
0----6487568
==============
0 1----6487552
1 2----6487556
2 0----6487560
3 5----6487564
4 0----6487568
5 5----6487572
6 6487552----6487576
7 0----6487580
8 2036688----6487584
9 0----6487588
10 4199400----6487592
11 0----6487596
12 0----6487600
13 0----6487604
14 103----6487608
15 0----6487612
16 4225568----6487616
17 0----6487620
18 0----6487624
19 0----6487628
20 0----6487632
21 0----6487636
22 0----6487640
23 0----6487644
24 0----6487648
25 0----6487652
26 0----6487656
27 0----6487660
28 0----6487664
29 0----6487668
30 0----6487672
31 0----6487676
32 0----6487680
33 0----6487684
34 0----6487688
35 0----6487692
36 0----6487696
37 0----6487700
38 0----6487704
39 0----6487708
40 0----6487712
41 0----6487716
42 0----6487720
43 0----6487724
44 0----6487728
45 0----6487732
46 0----6487736
47 0----6487740
48 1097016792----6487744
49 122----6487748
50 0----6487752
51 0----6487756
52 0----6487760
53 0----6487764
54 0----6487768
55 0----6487772
56 0----6487776
57 0----6487780
58 0----6487784
59 0----6487788
60 0----6487792
61 0----6487796
62 4199707----6487800
63 0----6487804
64 0----6487808
65 0----6487812
66 0----6487816
67 0----6487820
68 0----6487824
69 0----6487828
70 0----6487832
71 0----6487836
72 0----6487840
73 0----6487844
74 -1885310924----6487848
75 32762----6487852
76 0----6487856
77 0----6487860
78 0----6487864
79 0----6487868
80 0----6487872
81 0----6487876
82 0----6487880
83 0----6487884
84 0----6487888
85 0----6487892
86 -1882315183----6487896
87 32762----6487900
88 0----6487904
89 0----6487908
90 0----6487912
91 0----6487916
92 0----6487920
93 0----6487924
94 0----6487928
95 0----6487932
96 0----6487936
97 0----6487940
98 0----6487944
99 0----6487948
100 0----6487952
101 0----6487956
102 0----6487960
103 0----6487964
104 0----6487968
105 0----6487972
106 0----6487976
107 0----6487980
108 -1232----6487984
109 1256----6487988
110 -1232----6487992
111 1232----6487996
112 25----6488000
113 0----6488004
114 0----6488008
115 0----6488012
116 0----6488016
117 0----6488020
118 0----6488024
119 0----6488028
120 0----6488032
121 0----6488036
122 0----6488040
123 0----6488044
124 0----6488048
125 0----6488052
126 0----6488056
127 0----6488060

--------------------------------
Process exited after 1.201 seconds with return value 3221225477
Press any key to continue . . .



















