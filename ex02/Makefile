NAME = ex02
CXX = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp \
	   Bureaucrat.cpp \
	   AForm.cpp \
	   ShrubberyCreationForm.cpp \
	   RobotomyRequestForm.cpp \
	   PresidentialPardonForm.cpp
Headers = Bureaucrat.hpp \
		  AForm.hpp \
		  ShrubberyCreationForm.hpp \
		  RobotomyRequestForm.hpp \
		  PresidentialPardonForm.hpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f


all: $(NAME)


$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)


%.o: %.cpp $(Headers)
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJS)


fclean: clean
	$(RM) $(NAME)


re: fclean all