
Steps to compile:
    
    git clone https://github.com/clab/dynet.git
    cd dynet
    cd examples
    git clone this REPO
    mv RNNG-Dynet/CMakeLists.txt ../    -- where ../ is dynet/
    mv RNNG-Dynet/rnng/CMakeLists.txt ./
    mv RNNG-Dynet/rnng/ ./
    cd ../
    cmake -DEIGEN3_INCLUDE_DIR=/u/miguelba/tools/eigen/ -DENABLE_CPP_EXAMPLES=ON -DENABLE_BOOST=ON -DBOOST_ROOT=/opt/share/boost-1.57.0/
    make -j 20
    cd examples/  -- here is your compiled file
    cp -r rnng/*.py ./

Download and compile EVALB (http://nlp.cs.nyu.edu/evalb/) and put it in the examples/ directory.

Once this is done, just follow the training steps here: https://github.com/clab/rnng (where --cnn-mem should be --dynet-mem now.)

    
This will train a discriminative parser (see https://github.com/clab/rnng for the other commands):

    ./nt-parser --dynet-mem 1700 -x -T [train.oracle] -d [dev.oracle] -C [PTB/dev.24] -P -t --pretrained_dim 100 -w [sskip.100.vectors] --lstm_input_dim 128 --hidden_dim 128 -D 0.2
    
This will train a generative parser (see https://github.com/clab/rnng for the other commands):

    ./nt-parser-gen --dynet-mem 5000 -x -T [train-gen.oracle] -d [dev-gen.oracle] -t --clusters rnng/clusters-train-berk.txt --input_dim 256 --lstm_input_dim 256 --hidden_dim 256 -D 0.3
