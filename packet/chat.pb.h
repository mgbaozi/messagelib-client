// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: chat.proto

#ifndef PROTOBUF_chat_2eproto__INCLUDED
#define PROTOBUF_chat_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

namespace chat {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_chat_2eproto();
void protobuf_AssignDesc_chat_2eproto();
void protobuf_ShutdownFile_chat_2eproto();

class Send;
class Receive;
class Response;

enum Response_Error {
  Response_Error_SUCCESS = 0,
  Response_Error_OTHER_OFFLINE = 1,
  Response_Error_WAIT_FOR_OTHER_REPLY = 2
};
bool Response_Error_IsValid(int value);
const Response_Error Response_Error_Error_MIN = Response_Error_SUCCESS;
const Response_Error Response_Error_Error_MAX = Response_Error_WAIT_FOR_OTHER_REPLY;
const int Response_Error_Error_ARRAYSIZE = Response_Error_Error_MAX + 1;

const ::google::protobuf::EnumDescriptor* Response_Error_descriptor();
inline const ::std::string& Response_Error_Name(Response_Error value) {
  return ::google::protobuf::internal::NameOfEnum(
    Response_Error_descriptor(), value);
}
inline bool Response_Error_Parse(
    const ::std::string& name, Response_Error* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Response_Error>(
    Response_Error_descriptor(), name, value);
}
// ===================================================================

class Send : public ::google::protobuf::Message {
 public:
  Send();
  virtual ~Send();
  
  Send(const Send& from);
  
  inline Send& operator=(const Send& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Send& default_instance();
  
  void Swap(Send* other);
  
  // implements Message ----------------------------------------------
  
  Send* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Send& from);
  void MergeFrom(const Send& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required int32 message_id = 1;
  inline bool has_message_id() const;
  inline void clear_message_id();
  static const int kMessageIdFieldNumber = 1;
  inline ::google::protobuf::int32 message_id() const;
  inline void set_message_id(::google::protobuf::int32 value);
  
  // required string to_user = 2;
  inline bool has_to_user() const;
  inline void clear_to_user();
  static const int kToUserFieldNumber = 2;
  inline const ::std::string& to_user() const;
  inline void set_to_user(const ::std::string& value);
  inline void set_to_user(const char* value);
  inline void set_to_user(const char* value, size_t size);
  inline ::std::string* mutable_to_user();
  inline ::std::string* release_to_user();
  
  // required string content = 3;
  inline bool has_content() const;
  inline void clear_content();
  static const int kContentFieldNumber = 3;
  inline const ::std::string& content() const;
  inline void set_content(const ::std::string& value);
  inline void set_content(const char* value);
  inline void set_content(const char* value, size_t size);
  inline ::std::string* mutable_content();
  inline ::std::string* release_content();
  
  // @@protoc_insertion_point(class_scope:chat.Send)
 private:
  inline void set_has_message_id();
  inline void clear_has_message_id();
  inline void set_has_to_user();
  inline void clear_has_to_user();
  inline void set_has_content();
  inline void clear_has_content();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* to_user_;
  ::std::string* content_;
  ::google::protobuf::int32 message_id_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  friend void  protobuf_AddDesc_chat_2eproto();
  friend void protobuf_AssignDesc_chat_2eproto();
  friend void protobuf_ShutdownFile_chat_2eproto();
  
  void InitAsDefaultInstance();
  static Send* default_instance_;
};
// -------------------------------------------------------------------

class Receive : public ::google::protobuf::Message {
 public:
  Receive();
  virtual ~Receive();
  
  Receive(const Receive& from);
  
  inline Receive& operator=(const Receive& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Receive& default_instance();
  
  void Swap(Receive* other);
  
  // implements Message ----------------------------------------------
  
  Receive* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Receive& from);
  void MergeFrom(const Receive& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required int32 message_id = 1;
  inline bool has_message_id() const;
  inline void clear_message_id();
  static const int kMessageIdFieldNumber = 1;
  inline ::google::protobuf::int32 message_id() const;
  inline void set_message_id(::google::protobuf::int32 value);
  
  // required string from_user = 2;
  inline bool has_from_user() const;
  inline void clear_from_user();
  static const int kFromUserFieldNumber = 2;
  inline const ::std::string& from_user() const;
  inline void set_from_user(const ::std::string& value);
  inline void set_from_user(const char* value);
  inline void set_from_user(const char* value, size_t size);
  inline ::std::string* mutable_from_user();
  inline ::std::string* release_from_user();
  
  // required string content = 3;
  inline bool has_content() const;
  inline void clear_content();
  static const int kContentFieldNumber = 3;
  inline const ::std::string& content() const;
  inline void set_content(const ::std::string& value);
  inline void set_content(const char* value);
  inline void set_content(const char* value, size_t size);
  inline ::std::string* mutable_content();
  inline ::std::string* release_content();
  
  // @@protoc_insertion_point(class_scope:chat.Receive)
 private:
  inline void set_has_message_id();
  inline void clear_has_message_id();
  inline void set_has_from_user();
  inline void clear_has_from_user();
  inline void set_has_content();
  inline void clear_has_content();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* from_user_;
  ::std::string* content_;
  ::google::protobuf::int32 message_id_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  friend void  protobuf_AddDesc_chat_2eproto();
  friend void protobuf_AssignDesc_chat_2eproto();
  friend void protobuf_ShutdownFile_chat_2eproto();
  
  void InitAsDefaultInstance();
  static Receive* default_instance_;
};
// -------------------------------------------------------------------

class Response : public ::google::protobuf::Message {
 public:
  Response();
  virtual ~Response();
  
  Response(const Response& from);
  
  inline Response& operator=(const Response& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Response& default_instance();
  
  void Swap(Response* other);
  
  // implements Message ----------------------------------------------
  
  Response* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Response& from);
  void MergeFrom(const Response& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  typedef Response_Error Error;
  static const Error SUCCESS = Response_Error_SUCCESS;
  static const Error OTHER_OFFLINE = Response_Error_OTHER_OFFLINE;
  static const Error WAIT_FOR_OTHER_REPLY = Response_Error_WAIT_FOR_OTHER_REPLY;
  static inline bool Error_IsValid(int value) {
    return Response_Error_IsValid(value);
  }
  static const Error Error_MIN =
    Response_Error_Error_MIN;
  static const Error Error_MAX =
    Response_Error_Error_MAX;
  static const int Error_ARRAYSIZE =
    Response_Error_Error_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Error_descriptor() {
    return Response_Error_descriptor();
  }
  static inline const ::std::string& Error_Name(Error value) {
    return Response_Error_Name(value);
  }
  static inline bool Error_Parse(const ::std::string& name,
      Error* value) {
    return Response_Error_Parse(name, value);
  }
  
  // accessors -------------------------------------------------------
  
  // required int32 message_id = 1;
  inline bool has_message_id() const;
  inline void clear_message_id();
  static const int kMessageIdFieldNumber = 1;
  inline ::google::protobuf::int32 message_id() const;
  inline void set_message_id(::google::protobuf::int32 value);
  
  // required .chat.Response.Error err = 2;
  inline bool has_err() const;
  inline void clear_err();
  static const int kErrFieldNumber = 2;
  inline ::chat::Response_Error err() const;
  inline void set_err(::chat::Response_Error value);
  
  // @@protoc_insertion_point(class_scope:chat.Response)
 private:
  inline void set_has_message_id();
  inline void clear_has_message_id();
  inline void set_has_err();
  inline void clear_has_err();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::int32 message_id_;
  int err_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];
  
  friend void  protobuf_AddDesc_chat_2eproto();
  friend void protobuf_AssignDesc_chat_2eproto();
  friend void protobuf_ShutdownFile_chat_2eproto();
  
  void InitAsDefaultInstance();
  static Response* default_instance_;
};
// ===================================================================


// ===================================================================

// Send

// required int32 message_id = 1;
inline bool Send::has_message_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Send::set_has_message_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Send::clear_has_message_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Send::clear_message_id() {
  message_id_ = 0;
  clear_has_message_id();
}
inline ::google::protobuf::int32 Send::message_id() const {
  return message_id_;
}
inline void Send::set_message_id(::google::protobuf::int32 value) {
  set_has_message_id();
  message_id_ = value;
}

// required string to_user = 2;
inline bool Send::has_to_user() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Send::set_has_to_user() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Send::clear_has_to_user() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Send::clear_to_user() {
  if (to_user_ != &::google::protobuf::internal::kEmptyString) {
    to_user_->clear();
  }
  clear_has_to_user();
}
inline const ::std::string& Send::to_user() const {
  return *to_user_;
}
inline void Send::set_to_user(const ::std::string& value) {
  set_has_to_user();
  if (to_user_ == &::google::protobuf::internal::kEmptyString) {
    to_user_ = new ::std::string;
  }
  to_user_->assign(value);
}
inline void Send::set_to_user(const char* value) {
  set_has_to_user();
  if (to_user_ == &::google::protobuf::internal::kEmptyString) {
    to_user_ = new ::std::string;
  }
  to_user_->assign(value);
}
inline void Send::set_to_user(const char* value, size_t size) {
  set_has_to_user();
  if (to_user_ == &::google::protobuf::internal::kEmptyString) {
    to_user_ = new ::std::string;
  }
  to_user_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Send::mutable_to_user() {
  set_has_to_user();
  if (to_user_ == &::google::protobuf::internal::kEmptyString) {
    to_user_ = new ::std::string;
  }
  return to_user_;
}
inline ::std::string* Send::release_to_user() {
  clear_has_to_user();
  if (to_user_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = to_user_;
    to_user_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required string content = 3;
inline bool Send::has_content() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Send::set_has_content() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Send::clear_has_content() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Send::clear_content() {
  if (content_ != &::google::protobuf::internal::kEmptyString) {
    content_->clear();
  }
  clear_has_content();
}
inline const ::std::string& Send::content() const {
  return *content_;
}
inline void Send::set_content(const ::std::string& value) {
  set_has_content();
  if (content_ == &::google::protobuf::internal::kEmptyString) {
    content_ = new ::std::string;
  }
  content_->assign(value);
}
inline void Send::set_content(const char* value) {
  set_has_content();
  if (content_ == &::google::protobuf::internal::kEmptyString) {
    content_ = new ::std::string;
  }
  content_->assign(value);
}
inline void Send::set_content(const char* value, size_t size) {
  set_has_content();
  if (content_ == &::google::protobuf::internal::kEmptyString) {
    content_ = new ::std::string;
  }
  content_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Send::mutable_content() {
  set_has_content();
  if (content_ == &::google::protobuf::internal::kEmptyString) {
    content_ = new ::std::string;
  }
  return content_;
}
inline ::std::string* Send::release_content() {
  clear_has_content();
  if (content_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = content_;
    content_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// -------------------------------------------------------------------

// Receive

// required int32 message_id = 1;
inline bool Receive::has_message_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Receive::set_has_message_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Receive::clear_has_message_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Receive::clear_message_id() {
  message_id_ = 0;
  clear_has_message_id();
}
inline ::google::protobuf::int32 Receive::message_id() const {
  return message_id_;
}
inline void Receive::set_message_id(::google::protobuf::int32 value) {
  set_has_message_id();
  message_id_ = value;
}

// required string from_user = 2;
inline bool Receive::has_from_user() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Receive::set_has_from_user() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Receive::clear_has_from_user() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Receive::clear_from_user() {
  if (from_user_ != &::google::protobuf::internal::kEmptyString) {
    from_user_->clear();
  }
  clear_has_from_user();
}
inline const ::std::string& Receive::from_user() const {
  return *from_user_;
}
inline void Receive::set_from_user(const ::std::string& value) {
  set_has_from_user();
  if (from_user_ == &::google::protobuf::internal::kEmptyString) {
    from_user_ = new ::std::string;
  }
  from_user_->assign(value);
}
inline void Receive::set_from_user(const char* value) {
  set_has_from_user();
  if (from_user_ == &::google::protobuf::internal::kEmptyString) {
    from_user_ = new ::std::string;
  }
  from_user_->assign(value);
}
inline void Receive::set_from_user(const char* value, size_t size) {
  set_has_from_user();
  if (from_user_ == &::google::protobuf::internal::kEmptyString) {
    from_user_ = new ::std::string;
  }
  from_user_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Receive::mutable_from_user() {
  set_has_from_user();
  if (from_user_ == &::google::protobuf::internal::kEmptyString) {
    from_user_ = new ::std::string;
  }
  return from_user_;
}
inline ::std::string* Receive::release_from_user() {
  clear_has_from_user();
  if (from_user_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = from_user_;
    from_user_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required string content = 3;
inline bool Receive::has_content() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Receive::set_has_content() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Receive::clear_has_content() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Receive::clear_content() {
  if (content_ != &::google::protobuf::internal::kEmptyString) {
    content_->clear();
  }
  clear_has_content();
}
inline const ::std::string& Receive::content() const {
  return *content_;
}
inline void Receive::set_content(const ::std::string& value) {
  set_has_content();
  if (content_ == &::google::protobuf::internal::kEmptyString) {
    content_ = new ::std::string;
  }
  content_->assign(value);
}
inline void Receive::set_content(const char* value) {
  set_has_content();
  if (content_ == &::google::protobuf::internal::kEmptyString) {
    content_ = new ::std::string;
  }
  content_->assign(value);
}
inline void Receive::set_content(const char* value, size_t size) {
  set_has_content();
  if (content_ == &::google::protobuf::internal::kEmptyString) {
    content_ = new ::std::string;
  }
  content_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Receive::mutable_content() {
  set_has_content();
  if (content_ == &::google::protobuf::internal::kEmptyString) {
    content_ = new ::std::string;
  }
  return content_;
}
inline ::std::string* Receive::release_content() {
  clear_has_content();
  if (content_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = content_;
    content_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// -------------------------------------------------------------------

// Response

// required int32 message_id = 1;
inline bool Response::has_message_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Response::set_has_message_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Response::clear_has_message_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Response::clear_message_id() {
  message_id_ = 0;
  clear_has_message_id();
}
inline ::google::protobuf::int32 Response::message_id() const {
  return message_id_;
}
inline void Response::set_message_id(::google::protobuf::int32 value) {
  set_has_message_id();
  message_id_ = value;
}

// required .chat.Response.Error err = 2;
inline bool Response::has_err() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Response::set_has_err() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Response::clear_has_err() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Response::clear_err() {
  err_ = 0;
  clear_has_err();
}
inline ::chat::Response_Error Response::err() const {
  return static_cast< ::chat::Response_Error >(err_);
}
inline void Response::set_err(::chat::Response_Error value) {
  GOOGLE_DCHECK(::chat::Response_Error_IsValid(value));
  set_has_err();
  err_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace chat

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::chat::Response_Error>() {
  return ::chat::Response_Error_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_chat_2eproto__INCLUDED