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
///   File: Interface.hpp
///
/// Author: $author$
///   Date: 4/19/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_INTERFACE_HPP
#define _XOS_LOGGER_INTERFACE_HPP

#include "xos/logger/Output.hpp"

namespace xos {
namespace logger {

typedef Output InterfaceTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: InterfaceT
///////////////////////////////////////////////////////////////////////
template <class TImplements = InterfaceTImplements>
class _EXPORT_CLASS InterfaceT: virtual public TImplements {
public:
    typedef TImplements Implements;

    virtual bool Init() {
        return true;
    }
    virtual bool Fini() {
        return true;
    }

    using Implements::Log;
    virtual void Log
    (const Level& level, const Location& location, const Message& message) {
        Locker lock(*this);
        if ((this->IsEnabledFor(level))) {
            this->Log(location);
            this->Log(message);
            this->LogLn();
        }
    }
    virtual void Log
    (const Level& level, const Function& function, const Message& message) {
        Locker lock(*this);
        if ((this->IsEnabledFor(level))) {
            this->Log(function);
            this->Log(message);
            this->LogLn();
        }
    }
    virtual void Log
    (const Level& level, const Message& message) {
        Locker lock(*this);
        if ((this->IsEnabledFor(level))) {
            this->Log(message);
            this->LogLn();
        }
    }

    static InterfaceT* SetDefault(InterfaceT* to) {
        TheDefault() = to;
        return TheDefault();
    }
    static InterfaceT* Default() {
        return TheDefault();
    }
protected:
    static InterfaceT*& TheDefault() {
        static InterfaceT* theDefault = 0;
        return theDefault;
    }
};
typedef InterfaceT<> Interface;

typedef Interface BaseTImplements;
typedef xos::Base BaseTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: BaseT
///////////////////////////////////////////////////////////////////////
template <class TImplements = BaseTImplements, class TExtends = BaseTExtends>
class _EXPORT_CLASS BaseT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    BaseT(xos::Locked& locked, Level level): _locked(locked), _level(level) {
        Interface*& theDefault = Implements::TheDefault();
        if (!(theDefault)) {
            theDefault = this;
        }
    }
    BaseT(xos::Locked& locked): _locked(locked), _level(this->EnabledForDefault()) {
        Interface*& theDefault = Implements::TheDefault();
        if (!(theDefault)) {
            theDefault = this;
        }
    }
    BaseT(Level level): _locked(*this), _level(level) {
        Interface*& theDefault = Implements::TheDefault();
        if (!(theDefault)) {
            theDefault = this;
        }
    }
    BaseT(const BaseT &copy): _locked(copy.Locked()), _level(copy._level) {
        Interface*& theDefault = Implements::TheDefault();
        if (!(theDefault)) {
            theDefault = this;
        }
    }
    BaseT(): _locked(*this), _level(this->EnabledForDefault()) {
        Interface*& theDefault = Implements::TheDefault();
        if (!(theDefault)) {
            theDefault = this;
        }
    }
    virtual ~BaseT() {
        Interface*& theDefault = Implements::TheDefault();
        if ((theDefault) && (this == theDefault)) {
            theDefault = 0;
        }
    }

    virtual Level EnableFor(const Level& level) {
        Level enabledFor = this->EnabledFor();
        _level = level;
        return enabledFor;
    }
    virtual Level EnabledFor() const {
        return _level;
    }
    virtual bool IsEnabledFor(const Level& level) const {
        if ((level) && (level == (level & _level))) {
            return true;
        }
        return false;
    }

    virtual bool Lock() {
        if (&_locked != this) {
            return _locked.Lock(); 
        }
        return true;
    }
    virtual bool Unlock() {
        if (&_locked != this) {
            return _locked.Unlock(); 
        }
        return true;
    }
    virtual xos::Locked& Locked() const {
        if (&_locked != this) {
            return ((xos::Locked&)_locked); 
        }
        return ((xos::Locked&)*this);
    }

protected:
    xos::Locked& _locked;
    Level _level;
};
typedef BaseT<> Base;

} /// namespace logger
} /// namespace xos

#endif /// _XOS_LOGGER_INTERFACE_HPP 
