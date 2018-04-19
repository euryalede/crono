///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: Enabled.hpp
///
/// Author: $author$
///   Date: 4/19/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_ENABLED_HPP
#define _XOS_LOGGER_ENABLED_HPP

#include "xos/base/locked.hpp"
#include "xos/logger/Level.hpp"

namespace xos {
namespace logger {

typedef Unlocked EnabledTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: EnabledT
///////////////////////////////////////////////////////////////////////
template <class TImplements = EnabledTImplements>
class _EXPORT_CLASS EnabledT: virtual public TImplements {
public:
    typedef TImplements Implements;

    virtual Level EnableFor(const Level& level) {
        Level enabledFor = this->EnabledFor();
        return enabledFor;
    }
    virtual Level EnabledFor() const {
        Level enabledFor = this->EnabledForDefault();
        return enabledFor;
    }
    virtual bool IsEnabledFor(const Level& _level) const {
        Level enabledFor = EnabledFor();
        if ((_level) && (_level == (_level & enabledFor))) {
            return true;
        }
        return false;
    }
    virtual Level EnabledForDefault() const {
        Level level = XOS_LOGGING_LEVELS_DEFAULT;
        return level;
    }
};
typedef EnabledT<> Enabled;

} /// namespace logger
} /// namespace xos

#endif /// _XOS_LOGGER_ENABLED_HPP 
