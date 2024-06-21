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


#if !defined(_LOG4CXX_ROLLING_SIZE_AND_TIME_BASED_ROLLING_POLICY_H)
#define _LOG4CXX_ROLLING_SIZE_AND_TIME_BASED_ROLLING_POLICY_H

#include <log4cxx/rolling/rollingpolicybase.h>
#include <log4cxx/rolling/triggeringpolicy.h>
#include <log4cxx/rolling/sizebasedtriggeringpolicy.h>
#include <log4cxx/writerappender.h>
#include <log4cxx/helpers/outputstream.h>
#include <functional>

namespace LOG4CXX_NS
{

	namespace rolling
	{
		typedef enum {
			roll_reason_time = 1,
			roll_reason_filesize = 2
		}ROLL_REASON;
		class LOG4CXX_EXPORT SizeAndTimeBasedRollingPolicy : public virtual RollingPolicyBase,
			public virtual TriggeringPolicy
		{
			DECLARE_LOG4CXX_OBJECT(SizeAndTimeBasedRollingPolicy)
			BEGIN_LOG4CXX_CAST_MAP()
				LOG4CXX_CAST_ENTRY(SizeAndTimeBasedRollingPolicy)
				LOG4CXX_CAST_ENTRY_CHAIN(RollingPolicyBase)
				LOG4CXX_CAST_ENTRY_CHAIN(TriggeringPolicy)
			END_LOG4CXX_CAST_MAP()

		private:
			LOG4CXX_DECLARE_PRIVATE_MEMBER_PTR(SizeAndTimeBasedRollingPolicyPrivate, m_priv)


		private:
			ROLL_REASON _roll_reason = ROLL_REASON::roll_reason_time;
			unsigned int _current_roll_index = 1;
		public:
			SizeAndTimeBasedRollingPolicy();
			virtual ~SizeAndTimeBasedRollingPolicy();

			/**
			\copybrief RollingPolicyBase::activateOptions()

			Logs a warning if an option is not valid.

			\sa RollingPolicyBase::activateOptions()
			*/
			void activateOptions(helpers::Pool&) override;

			void setMultiprocess(bool multiprocess);

			/**
			 * {@inheritDoc}
			 */
			RolloverDescriptionPtr initialize(
				const   LogString& currentActiveFile,
				const   bool                    append,
				helpers::Pool& pool) override;

			/**
			 * {@inheritDoc}
			 */
			RolloverDescriptionPtr rollover(
				const   LogString& currentActiveFile,
				const   bool                    append,
				helpers::Pool& pool) override;

			/**
			 * Determines if a rollover may be appropriate at this time.  If
			 * true is returned, RolloverPolicy.rollover will be called but it
			 * can determine that a rollover is not warranted.
			 *
			 * @param appender A reference to the appender.
			 * @param event A reference to the currently event.
			 * @param filename The filename for the currently active log file.
			 * @param fileLength Length of the file in bytes.
			 * @return true if a rollover should occur.
			 */
			bool isTriggeringEvent(
				Appender* appender,
				const spi::LoggingEventPtr& event,
				const LogString& filename,
				size_t fileLength) override;

			/**
			\copybrief RollingPolicyBase::setOption()

			Supported options | Supported values | Default value
			:-------------- | :----------------: | :---------------:
			ThrowIOExceptionOnForkFailure | True,False | True

			\sa RollingPolicyBase::setOption()
			 */
			void setOption(const LogString& option, const LogString& value) override;

		protected:
			/**
			 * A map from "d" and "date" to a date conversion formatter.
			 *
			 * \sa FileDatePatternConverter
			 */
			LOG4CXX_NS::pattern::PatternMap getFormatSpecifiers() const override;

		private:

			/**
			 * Generate mmap file
			 */
			int createMMapFile(const std::string& lastfilename, LOG4CXX_NS::helpers::Pool& pool);

			/**
			 *  Detect if the mmap file is empty
			 */
			bool isMapFileEmpty(LOG4CXX_NS::helpers::Pool& pool);

			/**
			 *   init MMapFile
			 */
			void initMMapFile(const LogString& lastFileName, LOG4CXX_NS::helpers::Pool& pool);

			/**
			 *   lock MMapFile
			 */
			int lockMMapFile(int type);

			/**
			 *   unlock MMapFile
			 */
			int unLockMMapFile();

			/**
			 *   create MMapFile/lockFile
			 */
			const std::string createFile(const std::string& filename, const std::string& suffix, LOG4CXX_NS::helpers::Pool& pool);

		};

		LOG4CXX_PTR_DEF(SizeAndTimeBasedRollingPolicy);

	}
}

#endif


