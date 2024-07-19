all: core managers textures states
	g++ ./obj/*.o  ./obj/{managers,textures,states}/*.o -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer -o ./out

managers: obj/managers/image_manager.o obj/managers/font_manager.o

textures: obj/textures/base_texture.o obj/textures/image_texture.o obj/textures/text_texture.o

states: obj/states/base_state.o obj/states/mario_state.o obj/states/text_state.o obj/states/title_state.o obj/states/animated_state.o obj/states/select_state.o

core: obj/init.o obj/main.o obj/window.o

obj/%.o: src/%.cpp
	g++ -std=c++20 -c $< -I ./include -o $@

clean:
	rm ./obj/*.o ./obj/{textures,managers,states}/*.o ./out
