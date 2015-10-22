// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: fileformat.proto

#ifndef PROTOBUF_fileformat_2eproto__INCLUDED
#define PROTOBUF_fileformat_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
// @@protoc_insertion_point(includes)

namespace osmpbf {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_fileformat_2eproto();
void protobuf_AssignDesc_fileformat_2eproto();
void protobuf_ShutdownFile_fileformat_2eproto();

class blob_t;
class blob_header_t;

// ===================================================================

class blob_t : public ::google::protobuf::MessageLite {
 public:
  blob_t();
  virtual ~blob_t();

  blob_t(const blob_t& from);

  inline blob_t& operator=(const blob_t& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::std::string* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const blob_t& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const blob_t* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(blob_t* other);

  // implements Message ----------------------------------------------

  blob_t* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const blob_t& from);
  void MergeFrom(const blob_t& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bytes raw = 1;
  inline bool has_raw() const;
  inline void clear_raw();
  static const int kRawFieldNumber = 1;
  inline const ::std::string& raw() const;
  inline void set_raw(const ::std::string& value);
  inline void set_raw(const char* value);
  inline void set_raw(const void* value, size_t size);
  inline ::std::string* mutable_raw();
  inline ::std::string* release_raw();
  inline void set_allocated_raw(::std::string* raw);

  // optional int32 raw_size = 2;
  inline bool has_raw_size() const;
  inline void clear_raw_size();
  static const int kRawSizeFieldNumber = 2;
  inline ::google::protobuf::int32 raw_size() const;
  inline void set_raw_size(::google::protobuf::int32 value);

  // optional bytes zlib_data = 3;
  inline bool has_zlib_data() const;
  inline void clear_zlib_data();
  static const int kZlibDataFieldNumber = 3;
  inline const ::std::string& zlib_data() const;
  inline void set_zlib_data(const ::std::string& value);
  inline void set_zlib_data(const char* value);
  inline void set_zlib_data(const void* value, size_t size);
  inline ::std::string* mutable_zlib_data();
  inline ::std::string* release_zlib_data();
  inline void set_allocated_zlib_data(::std::string* zlib_data);

  // optional bytes lzma_data = 4;
  inline bool has_lzma_data() const;
  inline void clear_lzma_data();
  static const int kLzmaDataFieldNumber = 4;
  inline const ::std::string& lzma_data() const;
  inline void set_lzma_data(const ::std::string& value);
  inline void set_lzma_data(const char* value);
  inline void set_lzma_data(const void* value, size_t size);
  inline ::std::string* mutable_lzma_data();
  inline ::std::string* release_lzma_data();
  inline void set_allocated_lzma_data(::std::string* lzma_data);

  // optional bytes OBSOLETE_bzip2_data = 5 [deprecated = true];
  inline bool has_obsolete_bzip2_data() const PROTOBUF_DEPRECATED;
  inline void clear_obsolete_bzip2_data() PROTOBUF_DEPRECATED;
  static const int kOBSOLETEBzip2DataFieldNumber = 5;
  inline const ::std::string& obsolete_bzip2_data() const PROTOBUF_DEPRECATED;
  inline void set_obsolete_bzip2_data(const ::std::string& value) PROTOBUF_DEPRECATED;
  inline void set_obsolete_bzip2_data(const char* value) PROTOBUF_DEPRECATED;
  inline void set_obsolete_bzip2_data(const void* value, size_t size) PROTOBUF_DEPRECATED;
  inline ::std::string* mutable_obsolete_bzip2_data() PROTOBUF_DEPRECATED;
  inline ::std::string* release_obsolete_bzip2_data() PROTOBUF_DEPRECATED;
  inline void set_allocated_obsolete_bzip2_data(::std::string* obsolete_bzip2_data) PROTOBUF_DEPRECATED;

  // @@protoc_insertion_point(class_scope:osmpbf.blob_t)
 private:
  inline void set_has_raw();
  inline void clear_has_raw();
  inline void set_has_raw_size();
  inline void clear_has_raw_size();
  inline void set_has_zlib_data();
  inline void clear_has_zlib_data();
  inline void set_has_lzma_data();
  inline void clear_has_lzma_data();
  inline void set_has_obsolete_bzip2_data();
  inline void clear_has_obsolete_bzip2_data();

  ::std::string _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* raw_;
  ::std::string* zlib_data_;
  ::std::string* lzma_data_;
  ::std::string* obsolete_bzip2_data_;
  ::google::protobuf::int32 raw_size_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_fileformat_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_fileformat_2eproto();
  #endif
  friend void protobuf_AssignDesc_fileformat_2eproto();
  friend void protobuf_ShutdownFile_fileformat_2eproto();

  void InitAsDefaultInstance();
  static blob_t* default_instance_;
};
// -------------------------------------------------------------------

class blob_header_t : public ::google::protobuf::MessageLite {
 public:
  blob_header_t();
  virtual ~blob_header_t();

  blob_header_t(const blob_header_t& from);

  inline blob_header_t& operator=(const blob_header_t& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::std::string* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const blob_header_t& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const blob_header_t* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(blob_header_t* other);

  // implements Message ----------------------------------------------

  blob_header_t* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const blob_header_t& from);
  void MergeFrom(const blob_header_t& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline const ::std::string& type() const;
  inline void set_type(const ::std::string& value);
  inline void set_type(const char* value);
  inline void set_type(const char* value, size_t size);
  inline ::std::string* mutable_type();
  inline ::std::string* release_type();
  inline void set_allocated_type(::std::string* type);

  // optional bytes indexdata = 2;
  inline bool has_indexdata() const;
  inline void clear_indexdata();
  static const int kIndexdataFieldNumber = 2;
  inline const ::std::string& indexdata() const;
  inline void set_indexdata(const ::std::string& value);
  inline void set_indexdata(const char* value);
  inline void set_indexdata(const void* value, size_t size);
  inline ::std::string* mutable_indexdata();
  inline ::std::string* release_indexdata();
  inline void set_allocated_indexdata(::std::string* indexdata);

  // required int32 datasize = 3;
  inline bool has_datasize() const;
  inline void clear_datasize();
  static const int kDatasizeFieldNumber = 3;
  inline ::google::protobuf::int32 datasize() const;
  inline void set_datasize(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:osmpbf.blob_header_t)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_indexdata();
  inline void clear_has_indexdata();
  inline void set_has_datasize();
  inline void clear_has_datasize();

  ::std::string _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* type_;
  ::std::string* indexdata_;
  ::google::protobuf::int32 datasize_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_fileformat_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_fileformat_2eproto();
  #endif
  friend void protobuf_AssignDesc_fileformat_2eproto();
  friend void protobuf_ShutdownFile_fileformat_2eproto();

  void InitAsDefaultInstance();
  static blob_header_t* default_instance_;
};
// ===================================================================


// ===================================================================

// blob_t

// optional bytes raw = 1;
inline bool blob_t::has_raw() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void blob_t::set_has_raw() {
  _has_bits_[0] |= 0x00000001u;
}
inline void blob_t::clear_has_raw() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void blob_t::clear_raw() {
  if (raw_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    raw_->clear();
  }
  clear_has_raw();
}
inline const ::std::string& blob_t::raw() const {
  // @@protoc_insertion_point(field_get:osmpbf.blob_t.raw)
  return *raw_;
}
inline void blob_t::set_raw(const ::std::string& value) {
  set_has_raw();
  if (raw_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    raw_ = new ::std::string;
  }
  raw_->assign(value);
  // @@protoc_insertion_point(field_set:osmpbf.blob_t.raw)
}
inline void blob_t::set_raw(const char* value) {
  set_has_raw();
  if (raw_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    raw_ = new ::std::string;
  }
  raw_->assign(value);
  // @@protoc_insertion_point(field_set_char:osmpbf.blob_t.raw)
}
inline void blob_t::set_raw(const void* value, size_t size) {
  set_has_raw();
  if (raw_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    raw_ = new ::std::string;
  }
  raw_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:osmpbf.blob_t.raw)
}
inline ::std::string* blob_t::mutable_raw() {
  set_has_raw();
  if (raw_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    raw_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:osmpbf.blob_t.raw)
  return raw_;
}
inline ::std::string* blob_t::release_raw() {
  clear_has_raw();
  if (raw_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = raw_;
    raw_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void blob_t::set_allocated_raw(::std::string* raw) {
  if (raw_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete raw_;
  }
  if (raw) {
    set_has_raw();
    raw_ = raw;
  } else {
    clear_has_raw();
    raw_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:osmpbf.blob_t.raw)
}

// optional int32 raw_size = 2;
inline bool blob_t::has_raw_size() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void blob_t::set_has_raw_size() {
  _has_bits_[0] |= 0x00000002u;
}
inline void blob_t::clear_has_raw_size() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void blob_t::clear_raw_size() {
  raw_size_ = 0;
  clear_has_raw_size();
}
inline ::google::protobuf::int32 blob_t::raw_size() const {
  // @@protoc_insertion_point(field_get:osmpbf.blob_t.raw_size)
  return raw_size_;
}
inline void blob_t::set_raw_size(::google::protobuf::int32 value) {
  set_has_raw_size();
  raw_size_ = value;
  // @@protoc_insertion_point(field_set:osmpbf.blob_t.raw_size)
}

// optional bytes zlib_data = 3;
inline bool blob_t::has_zlib_data() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void blob_t::set_has_zlib_data() {
  _has_bits_[0] |= 0x00000004u;
}
inline void blob_t::clear_has_zlib_data() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void blob_t::clear_zlib_data() {
  if (zlib_data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    zlib_data_->clear();
  }
  clear_has_zlib_data();
}
inline const ::std::string& blob_t::zlib_data() const {
  // @@protoc_insertion_point(field_get:osmpbf.blob_t.zlib_data)
  return *zlib_data_;
}
inline void blob_t::set_zlib_data(const ::std::string& value) {
  set_has_zlib_data();
  if (zlib_data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    zlib_data_ = new ::std::string;
  }
  zlib_data_->assign(value);
  // @@protoc_insertion_point(field_set:osmpbf.blob_t.zlib_data)
}
inline void blob_t::set_zlib_data(const char* value) {
  set_has_zlib_data();
  if (zlib_data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    zlib_data_ = new ::std::string;
  }
  zlib_data_->assign(value);
  // @@protoc_insertion_point(field_set_char:osmpbf.blob_t.zlib_data)
}
inline void blob_t::set_zlib_data(const void* value, size_t size) {
  set_has_zlib_data();
  if (zlib_data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    zlib_data_ = new ::std::string;
  }
  zlib_data_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:osmpbf.blob_t.zlib_data)
}
inline ::std::string* blob_t::mutable_zlib_data() {
  set_has_zlib_data();
  if (zlib_data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    zlib_data_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:osmpbf.blob_t.zlib_data)
  return zlib_data_;
}
inline ::std::string* blob_t::release_zlib_data() {
  clear_has_zlib_data();
  if (zlib_data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = zlib_data_;
    zlib_data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void blob_t::set_allocated_zlib_data(::std::string* zlib_data) {
  if (zlib_data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete zlib_data_;
  }
  if (zlib_data) {
    set_has_zlib_data();
    zlib_data_ = zlib_data;
  } else {
    clear_has_zlib_data();
    zlib_data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:osmpbf.blob_t.zlib_data)
}

// optional bytes lzma_data = 4;
inline bool blob_t::has_lzma_data() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void blob_t::set_has_lzma_data() {
  _has_bits_[0] |= 0x00000008u;
}
inline void blob_t::clear_has_lzma_data() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void blob_t::clear_lzma_data() {
  if (lzma_data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    lzma_data_->clear();
  }
  clear_has_lzma_data();
}
inline const ::std::string& blob_t::lzma_data() const {
  // @@protoc_insertion_point(field_get:osmpbf.blob_t.lzma_data)
  return *lzma_data_;
}
inline void blob_t::set_lzma_data(const ::std::string& value) {
  set_has_lzma_data();
  if (lzma_data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    lzma_data_ = new ::std::string;
  }
  lzma_data_->assign(value);
  // @@protoc_insertion_point(field_set:osmpbf.blob_t.lzma_data)
}
inline void blob_t::set_lzma_data(const char* value) {
  set_has_lzma_data();
  if (lzma_data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    lzma_data_ = new ::std::string;
  }
  lzma_data_->assign(value);
  // @@protoc_insertion_point(field_set_char:osmpbf.blob_t.lzma_data)
}
inline void blob_t::set_lzma_data(const void* value, size_t size) {
  set_has_lzma_data();
  if (lzma_data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    lzma_data_ = new ::std::string;
  }
  lzma_data_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:osmpbf.blob_t.lzma_data)
}
inline ::std::string* blob_t::mutable_lzma_data() {
  set_has_lzma_data();
  if (lzma_data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    lzma_data_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:osmpbf.blob_t.lzma_data)
  return lzma_data_;
}
inline ::std::string* blob_t::release_lzma_data() {
  clear_has_lzma_data();
  if (lzma_data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = lzma_data_;
    lzma_data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void blob_t::set_allocated_lzma_data(::std::string* lzma_data) {
  if (lzma_data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete lzma_data_;
  }
  if (lzma_data) {
    set_has_lzma_data();
    lzma_data_ = lzma_data;
  } else {
    clear_has_lzma_data();
    lzma_data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:osmpbf.blob_t.lzma_data)
}

// optional bytes OBSOLETE_bzip2_data = 5 [deprecated = true];
inline bool blob_t::has_obsolete_bzip2_data() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void blob_t::set_has_obsolete_bzip2_data() {
  _has_bits_[0] |= 0x00000010u;
}
inline void blob_t::clear_has_obsolete_bzip2_data() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void blob_t::clear_obsolete_bzip2_data() {
  if (obsolete_bzip2_data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    obsolete_bzip2_data_->clear();
  }
  clear_has_obsolete_bzip2_data();
}
inline const ::std::string& blob_t::obsolete_bzip2_data() const {
  // @@protoc_insertion_point(field_get:osmpbf.blob_t.OBSOLETE_bzip2_data)
  return *obsolete_bzip2_data_;
}
inline void blob_t::set_obsolete_bzip2_data(const ::std::string& value) {
  set_has_obsolete_bzip2_data();
  if (obsolete_bzip2_data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    obsolete_bzip2_data_ = new ::std::string;
  }
  obsolete_bzip2_data_->assign(value);
  // @@protoc_insertion_point(field_set:osmpbf.blob_t.OBSOLETE_bzip2_data)
}
inline void blob_t::set_obsolete_bzip2_data(const char* value) {
  set_has_obsolete_bzip2_data();
  if (obsolete_bzip2_data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    obsolete_bzip2_data_ = new ::std::string;
  }
  obsolete_bzip2_data_->assign(value);
  // @@protoc_insertion_point(field_set_char:osmpbf.blob_t.OBSOLETE_bzip2_data)
}
inline void blob_t::set_obsolete_bzip2_data(const void* value, size_t size) {
  set_has_obsolete_bzip2_data();
  if (obsolete_bzip2_data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    obsolete_bzip2_data_ = new ::std::string;
  }
  obsolete_bzip2_data_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:osmpbf.blob_t.OBSOLETE_bzip2_data)
}
inline ::std::string* blob_t::mutable_obsolete_bzip2_data() {
  set_has_obsolete_bzip2_data();
  if (obsolete_bzip2_data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    obsolete_bzip2_data_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:osmpbf.blob_t.OBSOLETE_bzip2_data)
  return obsolete_bzip2_data_;
}
inline ::std::string* blob_t::release_obsolete_bzip2_data() {
  clear_has_obsolete_bzip2_data();
  if (obsolete_bzip2_data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = obsolete_bzip2_data_;
    obsolete_bzip2_data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void blob_t::set_allocated_obsolete_bzip2_data(::std::string* obsolete_bzip2_data) {
  if (obsolete_bzip2_data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete obsolete_bzip2_data_;
  }
  if (obsolete_bzip2_data) {
    set_has_obsolete_bzip2_data();
    obsolete_bzip2_data_ = obsolete_bzip2_data;
  } else {
    clear_has_obsolete_bzip2_data();
    obsolete_bzip2_data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:osmpbf.blob_t.OBSOLETE_bzip2_data)
}

// -------------------------------------------------------------------

// blob_header_t

// required string type = 1;
inline bool blob_header_t::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void blob_header_t::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void blob_header_t::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void blob_header_t::clear_type() {
  if (type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    type_->clear();
  }
  clear_has_type();
}
inline const ::std::string& blob_header_t::type() const {
  // @@protoc_insertion_point(field_get:osmpbf.blob_header_t.type)
  return *type_;
}
inline void blob_header_t::set_type(const ::std::string& value) {
  set_has_type();
  if (type_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    type_ = new ::std::string;
  }
  type_->assign(value);
  // @@protoc_insertion_point(field_set:osmpbf.blob_header_t.type)
}
inline void blob_header_t::set_type(const char* value) {
  set_has_type();
  if (type_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    type_ = new ::std::string;
  }
  type_->assign(value);
  // @@protoc_insertion_point(field_set_char:osmpbf.blob_header_t.type)
}
inline void blob_header_t::set_type(const char* value, size_t size) {
  set_has_type();
  if (type_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    type_ = new ::std::string;
  }
  type_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:osmpbf.blob_header_t.type)
}
inline ::std::string* blob_header_t::mutable_type() {
  set_has_type();
  if (type_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    type_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:osmpbf.blob_header_t.type)
  return type_;
}
inline ::std::string* blob_header_t::release_type() {
  clear_has_type();
  if (type_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = type_;
    type_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void blob_header_t::set_allocated_type(::std::string* type) {
  if (type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete type_;
  }
  if (type) {
    set_has_type();
    type_ = type;
  } else {
    clear_has_type();
    type_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:osmpbf.blob_header_t.type)
}

// optional bytes indexdata = 2;
inline bool blob_header_t::has_indexdata() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void blob_header_t::set_has_indexdata() {
  _has_bits_[0] |= 0x00000002u;
}
inline void blob_header_t::clear_has_indexdata() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void blob_header_t::clear_indexdata() {
  if (indexdata_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    indexdata_->clear();
  }
  clear_has_indexdata();
}
inline const ::std::string& blob_header_t::indexdata() const {
  // @@protoc_insertion_point(field_get:osmpbf.blob_header_t.indexdata)
  return *indexdata_;
}
inline void blob_header_t::set_indexdata(const ::std::string& value) {
  set_has_indexdata();
  if (indexdata_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    indexdata_ = new ::std::string;
  }
  indexdata_->assign(value);
  // @@protoc_insertion_point(field_set:osmpbf.blob_header_t.indexdata)
}
inline void blob_header_t::set_indexdata(const char* value) {
  set_has_indexdata();
  if (indexdata_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    indexdata_ = new ::std::string;
  }
  indexdata_->assign(value);
  // @@protoc_insertion_point(field_set_char:osmpbf.blob_header_t.indexdata)
}
inline void blob_header_t::set_indexdata(const void* value, size_t size) {
  set_has_indexdata();
  if (indexdata_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    indexdata_ = new ::std::string;
  }
  indexdata_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:osmpbf.blob_header_t.indexdata)
}
inline ::std::string* blob_header_t::mutable_indexdata() {
  set_has_indexdata();
  if (indexdata_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    indexdata_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:osmpbf.blob_header_t.indexdata)
  return indexdata_;
}
inline ::std::string* blob_header_t::release_indexdata() {
  clear_has_indexdata();
  if (indexdata_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = indexdata_;
    indexdata_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void blob_header_t::set_allocated_indexdata(::std::string* indexdata) {
  if (indexdata_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete indexdata_;
  }
  if (indexdata) {
    set_has_indexdata();
    indexdata_ = indexdata;
  } else {
    clear_has_indexdata();
    indexdata_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:osmpbf.blob_header_t.indexdata)
}

// required int32 datasize = 3;
inline bool blob_header_t::has_datasize() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void blob_header_t::set_has_datasize() {
  _has_bits_[0] |= 0x00000004u;
}
inline void blob_header_t::clear_has_datasize() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void blob_header_t::clear_datasize() {
  datasize_ = 0;
  clear_has_datasize();
}
inline ::google::protobuf::int32 blob_header_t::datasize() const {
  // @@protoc_insertion_point(field_get:osmpbf.blob_header_t.datasize)
  return datasize_;
}
inline void blob_header_t::set_datasize(::google::protobuf::int32 value) {
  set_has_datasize();
  datasize_ = value;
  // @@protoc_insertion_point(field_set:osmpbf.blob_header_t.datasize)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace osmpbf

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_fileformat_2eproto__INCLUDED