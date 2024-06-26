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

#ifndef _LOG4CXX_SPI_REPOSITORY_SELECTOR_H
#define _LOG4CXX_SPI_REPOSITORY_SELECTOR_H

#include <log4cxx/helpers/object.h>

namespace LOG4CXX_NS
{
namespace spi
{
class LoggerRepository;
typedef std::shared_ptr<LoggerRepository> LoggerRepositoryPtr;

/**
The <code>LogManager</code> uses one (and only one)
<code>RepositorySelector</code> implementation to select the
{@link log4cxx::spi::LoggerRepository LoggerRepository}
    for a particular application context.

<p>It is the responsability of the <code>RepositorySelector</code>
implementation to track the application context. log4cxx makes no
assumptions about the application context or on its management.

<p>See also LogManager.
*/
class LOG4CXX_EXPORT RepositorySelector : public virtual helpers::Object
{
	public:
		DECLARE_ABSTRACT_LOG4CXX_OBJECT(RepositorySelector)
		virtual ~RepositorySelector() {}
		virtual LoggerRepositoryPtr getLoggerRepository() = 0;
};
LOG4CXX_PTR_DEF(RepositorySelector);
}  //namespace spi
} //namespace log4cxx

#endif //_LOG4CXX_SPI_REPOSITORY_SELECTOR_H
