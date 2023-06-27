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
        Extens�o/troco.cpp Beecrowd/2446-Troco/main.cpp "Beecrowd/1912 - Ajude Seu Madruga/solution.cpp")
