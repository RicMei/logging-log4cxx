/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _LOG4CXX_HELPERS_ISO_8601_DATE_FORMAT_H
#define _LOG4CXX_HELPERS_ISO_8601_DATE_FORMAT_H

#include <log4cxx/helpers/simpledateformat.h>

namespace LOG4CXX_NS
{
namespace helpers
{
/**
Formats a date in the format <b>yyyy-MM-dd HH:mm:ss,SSS</b> for example
"1999-11-27 15:49:37,459".

<p>Refer to the
<a href=http://www.cl.cam.ac.uk/~mgk25/iso-time.html>summary of the
International Standard Date and Time Notation</a> for more
information on this format.
*/
class LOG4CXX_EXPORT ISO8601DateFormat : public SimpleDateFormat
{
	public:
		ISO8601DateFormat()
			: SimpleDateFormat(LOG4CXX_STR("yyyy-MM-dd HH:mm:ss,SSS")) {}
};
}  // namespace helpers
} // namespace log4cxx

#endif // _LOG4CXX_HELPERS_ISO_8601_DATE_FORMAT_H

