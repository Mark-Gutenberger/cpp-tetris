BUILD_DIR =./ build SRC_DIR =./ src

									COMPILER = g++ CFLAGS =
								 -lncurses - I src

#== = DO NOT EDIT UNDER THIS LINE == =
												 .RECIPEPREFIX =
									 > CPP_FILES =
										 $(shell cd $(SRC_DIR) &&
										   find * -name "*.cpp") OBJ_FILES =
											 $(CPP_FILES
											   : %.cpp = $(BUILD_DIR) / %.o)
												 OBJ_DIRS =
													 $(sort $(dir $(OBJ_FILES)))

															 all : main

																   $(OBJ_FILES)
	: $(BUILD_DIR) / %.o : $(SRC_DIR) /
	  %.cpp > $(COMPILER) $(CFLAGS) - c $ < -o $ @

													 main
	: $(OBJ_DIRS) $(OBJ_FILES) > $(COMPILER) $(OBJ_FILES) - o main $(CFLAGS)

																$(OBJ_DIRS)
	: > mkdir - p $ @

														 clean
	: >
	  rm - rf $(BUILD_DIR) > rm - f main

									  .PHONY : all clean