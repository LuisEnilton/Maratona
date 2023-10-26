cmake_minimum_required(VERSION 3.25)
project(Maratona)

set(CMAKE_CXX_STANDARD 14)

include_directories(LeetCode)
include_directories("LeetCode/1047. Remove All Adjacent Duplicates In String")
include_directories("LeetCode/11. Container With Most Water")
include_directories("LeetCode/118 - Pascal's Triangle")
include_directories("LeetCode/119 - Pascal's Triangle II")
include_directories("LeetCode/14. Longest Common Prefix")
include_directories("LeetCode/155. Min Stack")
include_directories("LeetCode/198 - HouseRobber")
include_directories("LeetCode/2. Add Two Numbers")
include_directories("LeetCode/213 - House Robber II")
include_directories("LeetCode/221 - Maximal Square")
include_directories("LeetCode/3- Substring Without Repeating Characters")
include_directories("LeetCode/300 - Longest Increasing Subsequence")
include_directories("LeetCode/33. Search in Rotated Sorted Array")
include_directories("LeetCode/336 - Palindrome Pairs")
include_directories("LeetCode/35 - Search Insert Position")
include_directories("LeetCode/409 - Longest Palindrome")
include_directories("LeetCode/455 - Assign Cookies")
include_directories("LeetCode/486 - Predict the Winner")
include_directories("LeetCode/5-Longest Palindromic Substring")
include_directories("LeetCode/561 - Array Partition")
include_directories("LeetCode/62. Unique Paths")
include_directories("LeetCode/63. Unique Paths II")
include_directories("LeetCode/64 - Minimum Path Sum")
include_directories("LeetCode/69 - Sqrt(x)")
include_directories("LeetCode/7. Reverse Integer")
include_directories("LeetCode/70 - Climbing Stairs")
include_directories("LeetCode/74-Search a 2D Matrix")
include_directories("LeetCode/740-Delete and Earn")
include_directories("LeetCode/746 - Min Cost Climbing Stairs")
include_directories("LeetCode/796 - Rotate String")
include_directories("LeetCode/852-Peak Index in a Mountain Array")
include_directories("LeetCode/9. Palindrome Number")
include_directories("LeetCode/931. Minimum Falling Path Sum")

add_executable(Maratona
        "AtCoder/Frog 2/solution.cpp"
        AtCoder/Frog1/Solution.cpp
        "AtCoder/Knapsack 1/solution.cpp"
        "AtCoder/Knapsack 2/solution.cpp"
        "Beecrowd/1025 - Onde esta o Marmore/solution.cpp"
        "Beecrowd/1034-Festival de Est�tuas de Gelo/main.cpp"
        "Beecrowd/1076 - Desenhando Labirintos/Solution.cpp"
        "Beecrowd/1088 - Bolhas e Baldes/solution.cpp"
        "Beecrowd/1110 - Jogando Cartas Fora/solution.cpp"
        "Beecrowd/1112 - Schweisen/solution.cpp"
        "Beecrowd/1123 - Desvio de Rota/a.cpp"
        "Beecrowd/1123 - Desvio de Rota/solution.cpp"
        "Beecrowd/1128 -Ir e vir/solution.cpp"
        "Beecrowd/1162 - Organizador de Vag�es/solution.cpp"
        "Beecrowd/1222 - Concurso de Contos/solution.cpp"
        "Beecrowd/1237 - Compara��o de Substring/solution.cpp"
        "Beecrowd/1260 - Esp�cies de Madeira/solution.cpp"
        "Beecrowd/1261 - Pontos de Feno/solution.cpp"
        "Beecrowd/1286 - Motoboy/solution.cpp"
        "Beecrowd/1301 - Produto do Intervalo/solution.cpp"
        "Beecrowd/1340 - Eu Posso Adivinhar a Estrutura de Dados/solution.cpp"
        "Beecrowd/1373 - Sequ�ncias de DNA/solution.cpp"
        "Beecrowd/1476 - Caminh�o/solution.cpp"
        "Beecrowd/1523 - Estacionamento linear/solution.cpp"
        "Beecrowd/1523 - Estacionamento linear/teste.cpp"
        "Beecrowd/1764 - Itiner�rio do Papai Noel/solution.cpp"
        "Beecrowd/1774 - Roteadores/solution.cpp"
        "Beecrowd/1799 - O Rato no Labirinto/solution.cpp"
        "Beecrowd/1804 - Precisa-se de Matem�ticos em Marte/solution.cpp"
        "Beecrowd/1907 - Colora��o de Cen�rios de Jogos/solution.cpp"
        "Beecrowd/1912 - Ajude Seu Madruga/solution.cpp"
        "Beecrowd/1931 - Mania de Par/dadinho.cpp"
        "Beecrowd/1931 - Mania de Par/solution.cpp"
        "Beecrowd/2330 - Telemarketing/solution.cpp"
        "Beecrowd/2406 - Express�es/solution.cpp"
        "Beecrowd/2434 - Saldo do Vov�/Solution.cpp"
        "Beecrowd/2440 - Fam�lias de Troia/solution.cpp"
        Beecrowd/2446-Troco/main.cpp
        "Beecrowd/2683 - Espa�o de Projeto/solution.cpp"
        "Beecrowd/2784 - Ilhas/solution.cpp"
        "Beecrowd/2832 - Capsulas/solution.cpp"
        "Beecrowd/2854 - �rvore Geneal�gica/solution.cpp"
        Beecrowd/2892/solution.cpp
        "Beecrowd/2929 - Menor da Pilha/solution.cpp"
        "Beecrowd/2973 - Maratona Brasileira de Comedores de Pipoca/solution.cpp"
        "Beecrowd/3051 - Soma/Solution.cpp"
        "Beecrowd/3061 - Manchas de Pele/extra.cpp"
        "Beecrowd/3061 - Manchas de Pele/solution.cpp"
        "Beecrowd/3424- Achando os Mon�tonos N�o-Triviais Maximais/solution.cpp"
        "Beecrowd/3458 - Fabrica��o de Prote�nas/solution.cpp"
        Beecrowd/fibonacci.cpp
        Beecrowd/recursivas.cpp
        Beecrowd/Sapo.cpp
        "BixeCamp/Ordena��o e buscaBinaria/solution.cpp"
        "Codeforces/1832A -  New Palindrome/solution.cpp"
        "Codeforces/1853A - Desorting/solution.cpp"
        "Codeforces/4C - Registration system/solution.cpp"
        "Codeforces/540A - Combination Lock/solution.cpp"
        "Codeforces/706 - Hard problem/solution.cpp"
        "Codeforces/706B - Interesting drink/solution.cpp"
        "Codeforces/B. New Year and Ascent Sequence/solution.cpp"
        "Codeforces/B. Vanya and Lanterns/solution.cpp"
        "Codeforces/Codeforces 891/B -Maximum Rounding/solution.cpp"
        "Codeforces/Troynacci Query/solution.cpp"
        "Codeforces/USP/E. Fig trees of Hatshepsut/solution.cpp"
        "Codeforces/USP/G. Mmoohhaammeedd/solution.cpp"
        "Contest-Boca/Contest 8/A/Expressions.cpp"
        "Contest-Boca/Contest 8/C/Decimalxor.cpp"
        "Contest-Boca/Contest 8/D/solution.cpp"
        "Contest-Boca/Contest 8/E/Aqualin.cpp"
        "Contest-Boca/Contest 8/E/dadinho.cpp"
        "Contest-Boca/Contest 8/G/dadinho.cpp"
        "Contest-Boca/Contest 8/G/Panda.cpp"
        "Contest-Boca/Contest 8/H/Lecture.cpp"
        "Contest-Boca/Contest 8/K/Tracing.cpp"
        "Contest-Boca/Contest 9/a.cpp"
        "Contest-Boca/Contest 9/d.cpp"
        "Contest-Boca/Contest 9/f.cpp"
        "Contest-Boca/Contest 9/h.cpp"
        "Contest-Boca/Contest 9/i.cpp"
        Contest-Boca/Passado/Letter.cpp
        Contest-Boca/Passado/Pseudo.cpp
        "CSES/Introductory Problems/Bit Strings/solution.cpp"
        "CSES/Introductory Problems/Increasing Array/solution.cpp"
        "CSES/Introductory Problems/Missing Number/solution.cpp"
        "CSES/Introductory Problems/Number Spiral/solution.cpp"
        "CSES/Palindrome Queries/solution.cpp"
        "CSES/Introductory Problems/Permutations/solution.cpp"
        "CSES/Range Updates and Sums/solution.cpp"
        "CSES/Introductory Problems/Repetitions/solution.cpp"
        "CSES/String Matching/solution.cpp"
        "CSES/Introductory Problems/Weird Algorithm/solution.cpp"
        Extens�o/BIT/bitsolution.cpp
        Extens�o/BIT/caixas.cpp
        Extens�o/Grafos/buscas.cpp
        Extens�o/Grafos/caminho.cpp
        Extens�o/Grafos/extras.cpp
        Extens�o/Grafos/Grafo.cpp
        Extens�o/Grafos/mst.cpp
        Extens�o/Hash/StringHash_1Base.cpp
        "Extens�o/Inversion Count/ic.cpp"
        Extens�o/LCA/lca.cpp
        Extens�o/LCA/lca2.cpp
        Extens�o/LCA/lca3.cpp
        Extens�o/LIS/lis.cpp
        Extens�o/Primos/MDC.cpp
        Extens�o/Primos/optim.cpp
        "Extens�o/Programa��o din�mica/proteina.cpp"
        "Extens�o/Programa��o din�mica/sequencia.cpp"
        "Extens�o/Programa��o din�mica/subseq.cpp"
        "Extens�o/Programa��o din�mica/troco.cpp"
        "Extens�o/Two pointers/aula.cpp"
        "Extens�o/Two pointers/sanduiche.cpp"
        Fase-Zero/pedras.cpp
        "LeetCode/1047. Remove All Adjacent Duplicates In String/Solution.cpp"
        "LeetCode/1047. Remove All Adjacent Duplicates In String/Solution.h"
        "LeetCode/11. Container With Most Water/Solution.cpp"
        "LeetCode/11. Container With Most Water/Solution.h"
        "LeetCode/118 - Pascal's Triangle/Solution.cpp"
        "LeetCode/118 - Pascal's Triangle/Solution.h"
        "LeetCode/119 - Pascal's Triangle II/Solution.cpp"
        "LeetCode/119 - Pascal's Triangle II/Solution.h"
        "LeetCode/14. Longest Common Prefix/Solution.cpp"
        "LeetCode/14. Longest Common Prefix/Solution.h"
        "LeetCode/155. Min Stack/MinStack.cpp"
        "LeetCode/155. Min Stack/MinStack.h"
        "LeetCode/198 - HouseRobber/solution.cpp"
        "LeetCode/198 - HouseRobber/Solution.h"
        "LeetCode/2. Add Two Numbers/Solution.cpp"
        "LeetCode/2. Add Two Numbers/Solution.h"
        "LeetCode/213 - House Robber II/Solution.cpp"
        "LeetCode/213 - House Robber II/Solution.h"
        "LeetCode/221 - Maximal Square/Solution.cpp"
        "LeetCode/221 - Maximal Square/Solution.h"
        "LeetCode/3- Substring Without Repeating Characters/Solution.cpp"
        "LeetCode/3- Substring Without Repeating Characters/Solution.h"
        "LeetCode/300 - Longest Increasing Subsequence/Solution.cpp"
        "LeetCode/300 - Longest Increasing Subsequence/Solution.h"
        "LeetCode/33. Search in Rotated Sorted Array/Solution.cpp"
        "LeetCode/33. Search in Rotated Sorted Array/Solution.h"
        "LeetCode/336 - Palindrome Pairs/Solution.cpp"
        "LeetCode/336 - Palindrome Pairs/Solution.h"
        "LeetCode/35 - Search Insert Position/Solution.cpp"
        "LeetCode/35 - Search Insert Position/Solution.h"
        "LeetCode/409 - Longest Palindrome/Solution.cpp"
        "LeetCode/409 - Longest Palindrome/Solution.h"
        "LeetCode/455 - Assign Cookies/Solution.cpp"
        "LeetCode/455 - Assign Cookies/Solution.h"
        "LeetCode/486 - Predict the Winner/Solution.cpp"
        "LeetCode/486 - Predict the Winner/Solution.h"
        "LeetCode/5-Longest Palindromic Substring/Solution.cpp"
        "LeetCode/5-Longest Palindromic Substring/Solution.h"
        "LeetCode/561 - Array Partition/Solution.cpp"
        "LeetCode/561 - Array Partition/Solution.h"
        "LeetCode/62. Unique Paths/solution.cpp"
        "LeetCode/62. Unique Paths/Solution.h"
        "LeetCode/63. Unique Paths II/Solution.cpp"
        "LeetCode/63. Unique Paths II/Solution.h"
        "LeetCode/64 - Minimum Path Sum/solution.cpp"
        "LeetCode/64 - Minimum Path Sum/Solution.h"
        "LeetCode/69 - Sqrt(x)/Solution.cpp"
        "LeetCode/69 - Sqrt(x)/Solution.h"
        "LeetCode/7. Reverse Integer/Solution.cpp"
        "LeetCode/7. Reverse Integer/Solution.h"
        "LeetCode/70 - Climbing Stairs/Solution.cpp"
        "LeetCode/70 - Climbing Stairs/Solution.h"
        "LeetCode/70 - Climbing Stairs/tabulation.cpp"
        "LeetCode/70 - Climbing Stairs/tabulation.h"
        "LeetCode/74-Search a 2D Matrix/Solution.cpp"
        "LeetCode/74-Search a 2D Matrix/Solution.h"
        "LeetCode/740-Delete and Earn/solution.cpp"
        "LeetCode/740-Delete and Earn/Solution.h"
        "LeetCode/746 - Min Cost Climbing Stairs/Solution.cpp"
        "LeetCode/746 - Min Cost Climbing Stairs/Solution.h"
        "LeetCode/796 - Rotate String/Solution.cpp"
        "LeetCode/796 - Rotate String/Solution.h"
        "LeetCode/852-Peak Index in a Mountain Array/solution.cpp"
        "LeetCode/852-Peak Index in a Mountain Array/solution.h"
        "LeetCode/9. Palindrome Number/Solution.cpp"
        "LeetCode/9. Palindrome Number/Solution.h"
        "LeetCode/931. Minimum Falling Path Sum/Solution.cpp"
        "LeetCode/931. Minimum Falling Path Sum/Solution.h"
        LeetCode/Solution.cpp
        LeetCode/Solution.h
        "Neps Academy/Arranha-c�u/solution.cpp"
        "Neps Academy/Caminho das pontes/solution.cpp"
        "Neps Academy/Chaves/solution.cpp"
        "Neps Academy/Crit�rios de Divisibilidade 1/solution.cpp"
        "Neps Academy/C�digo (OBI 2015)/solution.cpp"
        "Neps Academy/Danoninho/solution.cpp"
        "Neps Academy/Dentista/Dentista.cpp"
        "Neps Academy/Drone de entrega/solution.cpp"
        "Neps Academy/Gincana/solution.cpp"
        "Neps Academy/Idade de Camila/solution.cpp"
        "Neps Academy/Lanche na Empresa/solution.cpp"
        "Neps Academy/MDC Sequenciado/solution.cpp"
        "Neps Academy/Primos menores/solution.cpp"
        "Neps Academy/Riemann Ataca Novamente/solution.cpp"
        "Neps Academy/Selos/solution.cpp"
        "Neps Academy/Ta ligado/solution.cpp"
        "Neps Academy/Toca do Saci/solution.cpp"
        "Neps Academy/Todos os Divisores/solution.cpp"
        "Neps Academy/Troca/solution.cpp"
        "Neps Academy/� primo/solution.cpp"
        "SBC/Prova-2008/A - Apagando e Ganhando/solution.cpp"
        "SPOJ/CSUMQ - Cumulative Sum Query/solution.cpp"
        "SPOJ/I AM VERY BUSY/solution.cpp"
        "SPOJ/PRIME1 - Prime Generator/solution.cpp"
        "SPOJ/TULIPNUM - Tulip And Numbers/solution.cpp"
        "UVA/583-Prime Factors/solution.cpp"
        "VJudge/Atividade - LCA/A - Lowest Common Ancestor/solution.cpp"
        "VJudge/Atividade - LCA/B - Min Max Roads/solution.cpp"
        "VJudge/Atividade - LCA/C - Planets Queries I/solution.cpp"
        "VJudge/Atividade - LCA/D - Kth Ancestor/solution.cpp"
        "VJudge/Atividade - LCA/E - Company Queries I/solution.cpp"
        "VJudge/Atividade - LCA/F - A and B and Lecture Rooms/solution.cpp"
        "VJudge/Atividade - Two Pointers/A -Alice, Bob and Chocolate/solution.cpp"
        "VJudge/Atividade - Two Pointers/B -Sereja and Dima/dadinho.cpp"
        "VJudge/Atividade - Two Pointers/B -Sereja and Dima/solution.cpp"
        "VJudge/Atividade - Two Pointers/C -Balanced Team/dadinho.cpp"
        "VJudge/Atividade - Two Pointers/C -Balanced Team/solution.cpp"
        "VJudge/Atividade - Two Pointers/D - Three Parts of the Array/solution.cpp"
        "VJudge/Atividade - Two Pointers/E - Vasya and String/dadinho.cpp"
        "VJudge/Atividade - Two Pointers/E - Vasya and String/solution.cpp"
        "VJudge/Atividade - Two Pointers/F - Ada and Plants/solution.cpp"
        "VJudge/Atividade -SEG-BIT/A-Dynamic Range Sum Queries/solution.cpp"
        "VJudge/Atividade -SEG-BIT/B-Minimum/dadinho.cpp"
        "VJudge/Atividade -SEG-BIT/B-Minimum/solution.cpp"
        "VJudge/Atividade -SEG-BIT/C - XOR/solution.cpp"
        "VJudge/Atividade -SEG-BIT/D - Inversion Count/solution.cpp"
        "VJudge/Atividade -SEG-BIT/D - Inversion Count/solutionBIT.cpp"
        "VJudge/Atividade -SEG-BIT/E-DistinctCharacters/dadinho.cpp"
        "VJudge/Atividade -SEG-BIT/E-DistinctCharacters/dadinho2.cpp"
        "VJudge/Atividade -SEG-BIT/E-DistinctCharacters/solution.cpp"
        "VJudge/Atividade -SEG-BIT/G - DQuey/solution.cpp"
        "VJudge/Atividade -SEG-BIT/H/solution.cpp"
        "VJudge/Atividade-An�lise Combinat�ria/A - Tiles/solution.cpp"
        "VJudge/Atividade-HashString/A - Finding Periods/solution.cpp"
        "VJudge/Atividade-HashString/A - Finding Periods/teste.cpp"
        "VJudge/Atividade-HashString/D - Check Transcription/solution.cpp"
        "VJudge/Atividade-HashString/G - The Untended Antiquity/solution.cpp"
        "VJudge/Atividade-Manacher e Z-Function/A- Longest Palindrome/solution.cpp"
        "VJudge/Atividade-Manacher e Z-Function/B - Longest Palindromic Substring/solution.cpp"
        "VJudge/Atividade-Manacher e Z-Function/C - Number of Palindromes/solution.cpp"
        "VJudge/Atividade-Manacher e Z-Function/D - Find String Roots/solution.cpp"
        "VJudge/Atividade-Manacher e Z-Function/E - Finding Periods/solution.cpp"
        "VJudge/Atividade-Manacher e Z-Function/F - Password/solution.cpp"
        "VJudge/Atividade-Manacher e Z-Function/G - MUH and Cube Walls/solution.cpp"
        "VJudge/Atividade-Manacher e Z-Function/H - Text Editor/solution.cpp"
        main.cpp
        Solution.cpp
        template.cpp
        teste.cpp Extensão/Geometria/solution.cpp "Codeforces/908C - New Year and Curling/solution.cpp" "Beecrowd/2665 - Hipercampo/solution.cpp" "Codeforces/1199B - Water Lily/solution.cpp" "Codeforces/842B - Gleb And Pizza/solution.cpp" "Codeforces/1248A - Integer Points/solution.cpp" "CSES/Sorting and Searching/Sum of Two Values/solution.cpp" "CSES/Sorting and Searching/Maximum Subarray Sum/solution.cpp" "CSES/Sorting and Searching/Stick Lengths/solution.cpp" "CSES/Graph Algorithms/Counting Rooms/solution.cpp" "Codeforces/20C - Dijsktra/solution.cpp" "CSES/Range Queries/Increasing Array Queries/solution.cpp" "CSES/Range Queries/Prefix Sum Queries.cpp" "CSES/Range Queries/Subarray Sum Queries.cpp" "CSES/Introductory Problems/Creating Strings/solution.cpp" "LeetCode/55 - Jump Game/Solution.cpp" "LeetCode/55 - Jump Game/Solution.h" "LeetCode/45 - Jump Game II/Solution.cpp" "LeetCode/45 - Jump Game II/Solution.h" "Beecrowd/1084 - Apagando e Ganhando/solution.cpp" "AtCoder/Contest 322/f.cpp" "AtCoder/Contest 322/f2.cpp" "LeetCode/2896 - Apply Operations to Make Two Strings Equal/Solution.cpp" "LeetCode/2896 - Apply Operations to Make Two Strings Equal/Solution.h" "CSES/Sorting and Searching/Collecting Numbers/solution.cpp" "CSES/Sorting and Searching/Collecting Numbers II/solution.cpp" "CSES/Sorting and Searching/Playlis/solution.cpp" "CSES/Sorting and Searching/Towers/solution.cpp" "LeetCode/128Longest Consecutive Sequence/Solution.cpp" "LeetCode/128Longest Consecutive Sequence/Solution.h" Extensão/Split/split.cpp "CSES/Sorting and Searching/Concert Tickets/solution.cpp" "CSES/Sorting and Searching/Restaurant Customers/solution.cpp" "CSES/Sorting and Searching/Nested RangesCheck/solution.cpp" "OBI/Oficina/solution.cpp" OBI/Tesouro/solution.cpp "Codeforces/Codeforces 891/d.cpp" "Codeforces/Codeforces 891/e.cpp" "Codeforces/2023-2024 ACM-ICPC Latin American Regional Programming Contest/m.cpp" Codeforces/903/a.cpp "Codeforces/Contest 900(div3)/c.cpp" "CSES/Sorting and Searching/Sum of Three Values/solution.cpp" "CSES/Sorting and Searching/Nearest Smaller Values/solution.cpp" "CSES/Sorting and Searching/Subarray Sums I/solution.cpp" "CSES/Sorting and Searching/Subarray Distinct Values/solution.cpp")
