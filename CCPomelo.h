#ifndef __CCPomelo__
#define __CCPomelo__

#include "cocos2d.h"
#include "ExtensionMacros.h"

/** @brief handles asynchrounous pomelo sessions
 */
NS_CC_EXT_BEGIN

class CCPomelo : public CCObject
{
public:
	CCPomelo();
	virtual ~CCPomelo();

	int connect(unsigned short port,const char* ip);
	int send(const char* msg);

	inline void setRecvFunction(CCObject* pTarget, SEL_CallFuncND pSelector)
	{
		_pTarget = pTarget;
        _pSelector = pSelector;
        
        if (_pTarget)
        {
            _pTarget->retain();
        }
	}

	 /** Get the target of callback selector funtion, mainly used by CCHttpClient */
    inline CCObject* getTarget()
    {
        return _pTarget;
    }

    /** Get the selector function pointer, mainly used by CCHttpClient */
    inline SEL_CallFuncND getSelector()
    {
        return _pSelector;
    }


private:
	CCObject*          _pTarget;        /// callback target of pSelector function
    SEL_CallFuncND     _pSelector;      /// callback function, e.g. MyLayer::onHttpResponse(CCObject *sender, void *data)
   
};

NS_CC_EXT_END

#endif