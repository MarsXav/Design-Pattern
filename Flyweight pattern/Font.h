//
// Created by Dell on 2023/1/24.
//

#ifndef FLYWEIGHT_PATTERN_FONT_H
#define FLYWEIGHT_PATTERN_FONT_H

#include <bits/stdc++.h>

class Font_{
private:
    std::string key;
public:
    Font_(const std::string& key){ }
};

class FontFactory{
private:
    std::map<std::string, Font_*> fontPool;
public:
    Font_* GetFont(const std::string& key){
        auto item = fontPool.find(key);
        if (item != fontPool.end()) return fontPool[key];
        else {
            Font_* font = new Font_(key);
            fontPool[key] = font;
            return font;
        }
    }
};

#endif //FLYWEIGHT_PATTERN_FONT_H
