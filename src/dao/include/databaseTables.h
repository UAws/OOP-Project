#ifndef OOP_OOP_H
#define OOP_OOP_H

#include <sqlpp11/table.h>
#include <sqlpp11/data_types.h>
#include <sqlpp11/char_sequence.h>

namespace oop
{
  namespace People_
  {
    struct UserId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "user_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T userId;
            T& operator()() { return userId; }
            const T& operator()() const { return userId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::must_not_insert, sqlpp::tag::must_not_update>;
    };
    struct Name
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "name";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T name;
            T& operator()() { return name; }
            const T& operator()() const { return name; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::char_, sqlpp::tag::require_insert>;
    };
    struct Password
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "password";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T password;
            T& operator()() { return password; }
            const T& operator()() const { return password; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::char_>;
    };
    struct Title
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "title";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T title;
            T& operator()() { return title; }
            const T& operator()() const { return title; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::char_, sqlpp::tag::require_insert>;
    };
    struct IsActive
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "isActive";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T isActive;
            T& operator()() { return isActive; }
            const T& operator()() const { return isActive; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::boolean>;
    };
    struct UserLevel
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "userLevel";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T userLevel;
            T& operator()() { return userLevel; }
            const T& operator()() const { return userLevel; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
  } // namespace People_

  struct People: sqlpp::table_t<People,
               People_::UserId,
               People_::Name,
               People_::Password,
               People_::Title,
               People_::IsActive,
               People_::UserLevel>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "people";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T people;
        T& operator()() { return people; }
        const T& operator()() const { return people; }
      };
    };
  };
  namespace PeopleSubject_
  {
    struct UserId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "user_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T userId;
            T& operator()() { return userId; }
            const T& operator()() const { return userId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer>;
    };
    struct SubjectId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "subject_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T subjectId;
            T& operator()() { return subjectId; }
            const T& operator()() const { return subjectId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer>;
    };
  } // namespace PeopleSubject_

  struct PeopleSubject: sqlpp::table_t<PeopleSubject,
               PeopleSubject_::UserId,
               PeopleSubject_::SubjectId>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "peopleSubject";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T peopleSubject;
        T& operator()() { return peopleSubject; }
        const T& operator()() const { return peopleSubject; }
      };
    };
  };
  namespace Subject_
  {
    struct SubjectId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "subject_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T subjectId;
            T& operator()() { return subjectId; }
            const T& operator()() const { return subjectId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::must_not_insert, sqlpp::tag::must_not_update>;
    };
    struct Name
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "name";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T name;
            T& operator()() { return name; }
            const T& operator()() const { return name; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::char_, sqlpp::tag::can_be_null>;
    };
  } // namespace Subject_

  struct Subject: sqlpp::table_t<Subject,
               Subject_::SubjectId,
               Subject_::Name>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "subject";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T subject;
        T& operator()() { return subject; }
        const T& operator()() const { return subject; }
      };
    };
  };
} // namespace oop
#endif
