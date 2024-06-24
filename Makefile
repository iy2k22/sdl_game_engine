all: core managers textures states
	g++ ./obj/*.o  ./obj/{managers,textures,states}/*.o -l SDL2 -l SDL2_image -o ./out

managers: obj/managers/image_manager.o

textures: obj/textures/base_texture.o obj/textures/image_texture.o

states: obj/states/base_state.o obj/states/mario_state.o

core: obj/init.o obj/main.o obj/window.o

obj/%.o: src/%.cpp
	g++ -c $< -I ./include -o $@

clean:
	rm ./obj/*.o ./obj/{textures,managers,states}/*.o ./out
