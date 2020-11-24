#pragma once

#include <boost/stacktrace.hpp>

#include <logging/log_extra.hpp>
#include <utils/flags.hpp>

namespace logging::impl {

enum class LogExtraStacktraceFlags {
  kNone = 0,
  kNoCache = 1,
  kFrozen = (kNoCache << 1),
};

void ExtendLogExtraWithStacktrace(LogExtra& log_extra,
                                  const boost::stacktrace::stacktrace&,
                                  utils::Flags<LogExtraStacktraceFlags> = {});

bool ShouldLogStacktrace() noexcept;

}  // namespace logging::impl
