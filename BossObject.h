
#ifndef BOSS_OBJECT_H_
#define BOSS_OBJECT_H_

#include "BaseObject.h"
#include "CommonFunction.h"
#include "BulletObject.h"

#define GRAVITY_SPEED 0.8
#define MAX_FALL_SPEED 10;

#define BOSS_SPEED 2
#define PLAYER_HIGHT_VAL 18;

#define FRAME_NUM_32 32

#define BOSS_HP 20



class BossObject : public BaseObject
{
public:
    BossObject();
    ~BossObject();

    void set_x_val(int xp) {x_val_ = xp;}
    void set_y_val(int yp) {y_val_ = yp;}

    void set_x_pos(const int& xps) {x_pos_ = xps;}
    void set_y_pos(const int& yps) {y_pos_ = yps;}

    int get_x_pos() {return x_pos_;}
    int get_y_pos() {return y_pos_;}

    void set_clips();
    void Show(SDL_Renderer* des);
    bool LoadImg(std::string path, SDL_Renderer* screen);

    int get_width_frame() {return width_frame_;}
    int get_height_frame() {return height_frame_;}

    void SetMapXY(const int map_x, const int map_y) {map_x_ = map_x; map_y_ = map_y;}

    void CheckMap(Map& g_map);
    void CenterEntityOnMap(Map& g_map);
    void DoBoss(Map& g_map);
    void InitBoss();
    std::vector<BulletObject*> get_bullet_list() const {return bullet_list_;}
    void set_bullet_list(const std::vector<BulletObject*>& am_list) {bullet_list_ = am_list;}

    void InitBullet(SDL_Renderer* screen);
    void MakeBullet(SDL_Renderer* des, const int& x_limit, const& y_limmit);
    SDL_Rect GetRectFrame();
    void RemoveBullet();



private:
    float x_val_;
    float y_val_;
    int x_pos_;
    int y_pos_;

    int map_x_;
    int map_y_;
    int on_ground_;
    int think_time_;
    Input input_type_;
    int frame_;
    SDL_Rect frame_clip_[FRAME_NUM_32];

    int width_frame_;
    int height_frame_;
    std::vector<BulletObject*> bullet_list_;
};




#endif // BOSS_OBJECT_H_
