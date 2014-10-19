set(SOURCE_FILES
    Card.cpp
    Rules.cpp
	../include/Card.h
	../include/Rules.h
	../include/Exceptions.h
)

add_library(PokerImpl ${SOURCE_FILES})
