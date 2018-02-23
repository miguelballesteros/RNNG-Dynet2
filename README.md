
Steps to compile:
    
    git clone https://github.com/clab/dynet.git
    cd dynet
    cd examples
    git clone git@github.ibm.com:miguel-ballesteros/RNNG-Dynet.git
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

Datasets and embeddings are in 

    /u/whamza/ws/parsing/
    
This will train a discriminative parser (see https://github.com/clab/rnng for the other commands):

    ./nt-parser --dynet-mem 1700 -x -T /u/whamza/ws/parsing/train.oracle -d /u/whamza/ws/parsing/dev.oracle -C /u/whamza/ws/parsing/PTB/dev.24 -P -t --pretrained_dim 100 -w /u/whamza/ws/parsing/sskip.100.vectors --lstm_input_dim 128 --hidden_dim 128 -D 0.2
    
This will train a generative parser (see https://github.com/clab/rnng for the other commands):

    ./nt-parser-gen --dynet-mem 5000 -x -T /u/whamza/ws/parsing/train-gen.oracle -d /u/whamza/ws/parsing/dev-gen.oracle -t --clusters rnng/clusters-train-berk.txt --input_dim 256 --lstm_input_dim 256 --hidden_dim 256 -D 0.3
    
To run on GPU instead, we'll need to work on the r_log_softmax(a) and make it to run on a CPU device (by changing the code), but it is currently possible to compile it in GPU by adding these two options to the CMAKE command above:

    -DBACKEND=cuda -DCUDNN_ROOT=/usr/local/cuda
    
