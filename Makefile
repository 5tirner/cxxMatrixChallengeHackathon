SRCS = srcs/main.cpp\
	   srcs/Matrix/Matrix.cpp\
	   srcs/MatrixView/MatrixV.cpp\

OBJS = $(SRCS:.cpp=.o)

CXX	 = c++

CXXFLAGS = -Wall -Wextra -Werror -Ofast

EXCUTABLE = matric

REMOVE = rm -rf

all: $(EXCUTABLE)

$(EXCUTABLE) : $(OBJS)

	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXCUTABLE) && $(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(EXCUTABLE)

re: fclean all
	
