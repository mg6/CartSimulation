CXX=g++
CFLAGS=-std=c++11
LDFLAGS=$$(pkg-config --cflags --libs allegro-5.0 allegro_image-5.0 allegro_primitives-5.0 allegro_font-5.0 allegro_ttf-5.0)
INCLUDE=-I$(SRC)/.

BIN=./bin
SRC=./src
ASSETS=./assets
OUT=$(BIN)/CartSimulation
OBJS=$(BIN)/pendulum.o $(BIN)/cart.o $(BIN)/pendulumcart.o $(BIN)/simulation.o $(BIN)/main.o

all: prebuild $(OUT)

prebuild:
	cp -r $(ASSETS)/* $(BIN)/

$(OUT): $(OBJS)
	$(CXX) $(OBJS) -o $(OUT) $(INCLUDE) $(CFLAGS) $(LDFLAGS)

$(BIN)/%.o: $(SRC)/%.cpp
	$(CXX) $(CFLAGS) $< -c -o $@

clean:
	rm -rf $(BIN)/*o $(BIN)/CartSimulation

