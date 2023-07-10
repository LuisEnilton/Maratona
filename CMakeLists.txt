cmake_minimum_required(VERSION 3.25)
project(Maratona)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Beecrowd)
include_directories(Contest-Boca)
include_directories(Extens�o)

add_executable(Maratona
        "Beecrowd/1034-Festival de Est�tuas de Gelo/main.cpp"
        Beecrowd/2446-Troco/main.cpp
        Beecrowd/fibonacci.cpp
        Beecrowd/recursivas.cpp
        Beecrowd/Sapo.cpp
        Contest-Boca/Letter.cpp
        Contest-Boca/Pseudo.cpp
        Extens�o/proteina.cpp
        Extens�o/sequencia.cpp
        Extens�o/subseq.cpp
        Extens�o/troco.cpp Beecrowd/2446-Troco/main.cpp "Beecrowd/1912 - Ajude Seu Madruga/solution.cpp" "Beecrowd/3424- Achando os Monótonos Não-Triviais Maximais/solution.cpp" "Neps Academy/Drone de entrega/solution.cpp" "Neps Academy/Toca do Saci/solution.cpp" "Neps Academy/Gincana/solution.cpp" "Beecrowd/1907 - Coloração de Cenários de Jogos/solution.cpp" "Beecrowd/2784 - Ilhas/solution.cpp" "Beecrowd/1931 - Mania de Par/solution.cpp" "Beecrowd/1931 - Mania de Par/dadinho.cpp" Extensão/Grafos/mst.cpp "Beecrowd/3061 - Manchas de Pele/solution.cpp" "Beecrowd/1123 - Desvio de Rota/solution.cpp" "Beecrowd/3061 - Manchas de Pele/extra.cpp" "Neps Academy/Ta ligado/solution.cpp" "Beecrowd/2683 - Espaço de Projeto/solution.cpp" "Beecrowd/2854 - Árvore Genealógica/solution.cpp" "CodeForce/Atividade - Two Pointers/A - Alice, Bob and Chocolate/solution.cpp" "Neps Academy/Arranha-céu/solution.cpp" "CodeForce/Atividade - Two Pointers/F - Ada and Plants/solution.cpp" "Beecrowd/1260 - Espécies de Madeira/solution.cpp")
