//
//  Transform.hpp
//  Labirint
//
//  Created by marina porkhunova on 05.01.2023.
//

#ifndef Transform_hpp
#define Transform_hpp

#include <stdio.h>
#include "PositionPrimitives.hpp"
#include "Component.hpp"


class Transform : public Component
{
    COMPONENT_BODY(Transform)
    
    Point2D<int> position; // world
    Point2D<float> scale;

    bool _dirty;
protected:
    void Init() override;
public:
    
    const Point2D<int>& GetPosition();
    const Point2D<float>& GetScale();
    
    void Offset(int x, int y);
    void SetPosition(int x, int y);
    void SetScale(float x, float y);
    
    bool IsDirty();
    void ClearDirty();
    
    void Serialize(json &j) override;
    void Deserialize(json &j) override;
};

#endif /* Transform_hpp */




