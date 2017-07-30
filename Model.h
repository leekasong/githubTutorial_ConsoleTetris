#ifndef MODEL_H
#define MODEL_H

#include "common.h"

class Model{
    private:
        View *mp_view;
        Map *mp_map;
    public:
        Model();
        ~Model();
        int setView(View *pView);
        int notifyView();   //Notify view when some datas are changed;
};


#endif
