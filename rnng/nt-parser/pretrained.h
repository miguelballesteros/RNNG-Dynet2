#ifndef PARSER_PRETRAINED_H
#define PARSER_PRETRAINED_H

#include <unordered_map>
#include <vector>
#include <string>

namespace dynet { struct Dict; }

namespace parser {

void ReadEmbeddings_word2vec(const std::string& fname,
        dynet::Dict* dict,
        std::unordered_map<unsigned, std::vector<float>>* pretrained);

} // namespace parser

#endif
