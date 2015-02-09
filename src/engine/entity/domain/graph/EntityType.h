/*
 * EntityType.h
 *
 *  Created on: 16.01.2015
 *      Author: aschaeffer
 */

#ifndef SRC_ENGINE_ENTITY_ENTITYTYPE_H_
#define SRC_ENGINE_ENTITY_ENTITYTYPE_H_

#include "../TypeBase.h"
#include "../TypeRefPtr.h"

namespace inexor {
namespace entity {

class EntityType : public TypeBase
{
    public:
        EntityType(std::string name, bool persist, bool synchronize);
        EntityType(std::string name, bool persist, bool synchronize, TypeRefPtr<EntityType> parent);
        virtual ~EntityType() {};

        bool IsA(TypeRefPtr<EntityType> type);
        bool IsA(std::string uuid);
        bool IsExactlyA(TypeRefPtr<EntityType> type);
        bool IsExactlyA(std::string uuid);

    private:
        TypeRefPtr<EntityType> parent;

        // Include the default reference counting implementation.
        IMPLEMENT_REFCOUNTING(EntityType);

};

}
}

#endif /* SRC_ENGINE_ENTITY_ENTITYTYPE_H_ */