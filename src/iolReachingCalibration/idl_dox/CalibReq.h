/*
 * Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#ifndef YARP_THRIFT_GENERATOR_STRUCT_CalibReq
#define YARP_THRIFT_GENERATOR_STRUCT_CalibReq

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>

class CalibReq;


/**
 * CalibReq
 * IDL structure to send/receive points.
 */
class CalibReq : public yarp::os::idl::WirePortable {
public:
  // Fields
  /**
   * contain [ok]/[fail] on success/failure.
   */
  std::string result;
  /**
   * the x-coordinate.
   */
  double x;
  /**
   * the y-coordinate.
   */
  double y;
  /**
   * the z-coordinate.
   */
  double z;

  // Default constructor
  CalibReq() : result(""), x(0), y(0), z(0) {
  }

  // Constructor with field values
  CalibReq(const std::string& result,const double x,const double y,const double z) : result(result), x(x), y(y), z(z) {
  }

  // Copy constructor
  CalibReq(const CalibReq& __alt) : WirePortable(__alt)  {
    this->result = __alt.result;
    this->x = __alt.x;
    this->y = __alt.y;
    this->z = __alt.z;
  }

  // Assignment operator
  const CalibReq& operator = (const CalibReq& __alt) {
    this->result = __alt.result;
    this->x = __alt.x;
    this->y = __alt.y;
    this->z = __alt.z;
    return *this;
  }

  // read and write structure on a connection
  bool read(yarp::os::idl::WireReader& reader) override;
  bool read(yarp::os::ConnectionReader& connection) override;
  bool write(const yarp::os::idl::WireWriter& writer) const override;
  bool write(yarp::os::ConnectionWriter& connection) const override;

private:
  bool write_result(const yarp::os::idl::WireWriter& writer) const;
  bool nested_write_result(const yarp::os::idl::WireWriter& writer) const;
  bool write_x(const yarp::os::idl::WireWriter& writer) const;
  bool nested_write_x(const yarp::os::idl::WireWriter& writer) const;
  bool write_y(const yarp::os::idl::WireWriter& writer) const;
  bool nested_write_y(const yarp::os::idl::WireWriter& writer) const;
  bool write_z(const yarp::os::idl::WireWriter& writer) const;
  bool nested_write_z(const yarp::os::idl::WireWriter& writer) const;
  bool read_result(yarp::os::idl::WireReader& reader);
  bool nested_read_result(yarp::os::idl::WireReader& reader);
  bool read_x(yarp::os::idl::WireReader& reader);
  bool nested_read_x(yarp::os::idl::WireReader& reader);
  bool read_y(yarp::os::idl::WireReader& reader);
  bool nested_read_y(yarp::os::idl::WireReader& reader);
  bool read_z(yarp::os::idl::WireReader& reader);
  bool nested_read_z(yarp::os::idl::WireReader& reader);

public:

  std::string toString() const;

  // if you want to serialize this class without nesting, use this helper
  typedef yarp::os::idl::Unwrapped<CalibReq > unwrapped;

  class Editor : public yarp::os::Wire, public yarp::os::PortWriter {
  public:

    Editor() {
      group = 0;
      obj_owned = true;
      obj = new CalibReq;
      dirty_flags(false);
      yarp().setOwner(*this);
    }

    Editor(CalibReq& obj) {
      group = 0;
      obj_owned = false;
      edit(obj,false);
      yarp().setOwner(*this);
    }

    bool edit(CalibReq& obj, bool dirty = true) {
      if (obj_owned) delete this->obj;
      this->obj = &obj;
      obj_owned = false;
      dirty_flags(dirty);
      return true;
    }

    virtual ~Editor() {
    if (obj_owned) delete obj;
    }

    bool isValid() const {
      return obj!=0/*NULL*/;
    }

    CalibReq& state() { return *obj; }

    void begin() { group++; }

    void end() {
      group--;
      if (group==0&&is_dirty) communicate();
    }
    void set_result(const std::string& result) {
      will_set_result();
      obj->result = result;
      mark_dirty_result();
      communicate();
      did_set_result();
    }
    void set_x(const double x) {
      will_set_x();
      obj->x = x;
      mark_dirty_x();
      communicate();
      did_set_x();
    }
    void set_y(const double y) {
      will_set_y();
      obj->y = y;
      mark_dirty_y();
      communicate();
      did_set_y();
    }
    void set_z(const double z) {
      will_set_z();
      obj->z = z;
      mark_dirty_z();
      communicate();
      did_set_z();
    }
    const std::string& get_result() {
      return obj->result;
    }
    double get_x() {
      return obj->x;
    }
    double get_y() {
      return obj->y;
    }
    double get_z() {
      return obj->z;
    }
    virtual bool will_set_result() { return true; }
    virtual bool will_set_x() { return true; }
    virtual bool will_set_y() { return true; }
    virtual bool will_set_z() { return true; }
    virtual bool did_set_result() { return true; }
    virtual bool did_set_x() { return true; }
    virtual bool did_set_y() { return true; }
    virtual bool did_set_z() { return true; }
    void clean() {
      dirty_flags(false);
    }
    bool read(yarp::os::ConnectionReader& connection) override;
    bool write(yarp::os::ConnectionWriter& connection) const override;
  private:

    CalibReq *obj;

    bool obj_owned;
    int group;

    void communicate() {
      if (group!=0) return;
      if (yarp().canWrite()) {
        yarp().write(*this);
        clean();
      }
    }
    void mark_dirty() {
      is_dirty = true;
    }
    void mark_dirty_result() {
      if (is_dirty_result) return;
      dirty_count++;
      is_dirty_result = true;
      mark_dirty();
    }
    void mark_dirty_x() {
      if (is_dirty_x) return;
      dirty_count++;
      is_dirty_x = true;
      mark_dirty();
    }
    void mark_dirty_y() {
      if (is_dirty_y) return;
      dirty_count++;
      is_dirty_y = true;
      mark_dirty();
    }
    void mark_dirty_z() {
      if (is_dirty_z) return;
      dirty_count++;
      is_dirty_z = true;
      mark_dirty();
    }
    void dirty_flags(bool flag) {
      is_dirty = flag;
      is_dirty_result = flag;
      is_dirty_x = flag;
      is_dirty_y = flag;
      is_dirty_z = flag;
      dirty_count = flag ? 4 : 0;
    }
    bool is_dirty;
    int dirty_count;
    bool is_dirty_result;
    bool is_dirty_x;
    bool is_dirty_y;
    bool is_dirty_z;
  };
};

#endif
